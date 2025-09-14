#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener

import numpy as np
import cv2
from cv_bridge import CvBridge

from sensor_msgs.msg import CameraInfo, Image, PointCloud2
import sensor_msgs_py.point_cloud2 as pc2
from perception_msgs.msg import ObjectDetections, ObjectDetection, BoundingBox


class Point3D:
    def __init__(self, x, y, z, pid):
        self.x = x
        self.y = y
        self.z = z
        self.id = pid

def transform_point(point, T):
    """Transform LiDAR point to camera frame"""
    p_h = np.array([point[0], point[1], point[2], 1.0])
    p_cam_h = T @ p_h
    return p_cam_h[:3]


def project_to_image(p_cam, K):
    """Project camera coordinates to image plane"""
    p_img = K @ p_cam
    return np.array([p_img[0] / p_img[2], p_img[1] / p_img[2]])


def point_inside_bbox(pt, bbox):
    """Check if point lies inside axis-aligned bounding box"""
    xs = [bbox.k1.x, bbox.k2.x, bbox.k3.x, bbox.k4.x]
    ys = [bbox.k1.y, bbox.k2.y, bbox.k3.y, bbox.k4.y]
    return (min(xs) <= pt[0] <= max(xs)) and (min(ys) <= pt[1] <= max(ys))


class FusionNode(Node):
    def __init__(self):
        super().__init__("fusion_node")

        self.bridge = CvBridge()
        self.K = None
        self.latest_image = None
        self.latest_points = None
        self.detected_objects = []  # Will be filled from detections topic

        # TF listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Define frame ids
        self.camera_frame = "hero/rgb_front"
        self.lidar_frame = "hero/lidar"
        self.world_frame = "map"

        # Subscribers
        self.create_subscription(CameraInfo, "/carla/hero/rgb_front/camera_info", self.camera_info_cb, 10)
        self.create_subscription(Image, "/carla/hero/rgb_front/image", self.image_cb, 10)
        self.create_subscription(PointCloud2, "/carla/hero/lidar", self.lidar_cb, 10)
        self.create_subscription(ObjectDetections, "/detections", self.detections_cb, 10)

    def camera_info_cb(self, msg: CameraInfo):
        # Intrinsic matrix
        self.K = np.array(msg.k).reshape(3, 3)

    def image_cb(self, msg: Image):
        self.latest_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

    def detections_cb(self, msg: ObjectDetections):
        """Update detected objects from YOLO node"""
        self.detected_objects = msg.detections

    def lidar_cb(self, msg: PointCloud2):

        # Convert pointcloud2 to numpy array
        points = []
        for i, p in enumerate(pc2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True)):
            points.append(Point3D(p[0], p[1], p[2], i))
        self.latest_points = points

        # Run fusion only if all inputs available
        if self.K is not None and self.latest_image is not None and self.detected_objects:
            self.run_fusion()

    def run_fusion(self):
        img = self.latest_image.copy()

        if not self.detected_objects:
            # Show raw image (no boxes)
            cv2.imshow("Fusion", img)
            cv2.waitKey(1)
            return

        self.get_logger().info(f"Running fusion with {len(self.detected_objects)} detections")
        for obj in self.detected_objects:
            min_z = float("inf")

            # Extract bbox points
            pts = [(int(obj.bbox.k1.x), int(obj.bbox.k1.y)),
                   (int(obj.bbox.k2.x), int(obj.bbox.k2.y)),
                   (int(obj.bbox.k3.x), int(obj.bbox.k3.y)),
                   (int(obj.bbox.k4.x), int(obj.bbox.k4.y))]

            # Draw bbox
            cv2.polylines(img, [np.array(pts, np.int32)], isClosed=True,
                          color=(0, 255, 0), thickness=2)

            for p in self.latest_points:
                try:
                    # Transform LiDAR → Camera using TF
                    t = self.tf_buffer.lookup_transform(self.camera_frame,
                                                        self.lidar_frame,
                                                        rclpy.time.Time())
                    T = self.tf_to_matrix(t)
                    p_cam = transform_point((p.x, p.y, p.z), T)

                    if p_cam[2] <= 0:
                        continue

                    uv = project_to_image(p_cam, self.K)
                    u, v = int(uv[0]), int(uv[1])

                    if 0 <= u < img.shape[1] and 0 <= v < img.shape[0]:
                        if point_inside_bbox((u, v), obj.bbox):
                            cv2.circle(img, (u, v), 2, (0, 0, 255), -1)
                            min_z = min(min_z, p_cam[2])

                except Exception as e:
                    self.get_logger().warn(f"TF lookup failed: {e}")

            if min_z < float("inf"):
                cv2.putText(img, f"Depth: {min_z:.2f} m",
                            (pts[0][0], pts[0][1] - 10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 255), 2)

        cv2.imshow("Fusion", img)
        cv2.waitKey(1)

    def tf_to_matrix(self, transform):
        """Convert TF transform to 4x4 matrix"""
        trans = transform.transform.translation
        rot = transform.transform.rotation
        T = np.eye(4)
        T[:3, :3] = self.quaternion_to_rot(rot)
        T[:3, 3] = [trans.x, trans.y, trans.z]
        return T

    def quaternion_to_rot(self, q):
        """Quaternion → rotation matrix"""
        x, y, z, w = q.x, q.y, q.z, q.w
        return np.array([
            [1 - 2*(y*y + z*z), 2*(x*y - z*w),     2*(x*z + y*w)],
            [2*(x*y + z*w),     1 - 2*(x*x + z*z), 2*(y*z - x*w)],
            [2*(x*z - y*w),     2*(y*z + x*w),     1 - 2*(x*x + y*y)]
        ])


def main(args=None):
    rclpy.init(args=args)
    node = FusionNode()
    rclpy.spin(node)
    node.destroy_node()
    cv2.destroyAllWindows()
    rclpy.shutdown()


if __name__ == "__main__":
    main()