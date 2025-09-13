#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener
import tf_transformations

import numpy as np
import cv2
from cv_bridge import CvBridge

from sensor_msgs.msg import CameraInfo, Image, PointCloud2
import sensor_msgs_py.point_cloud2 as pc2


class Point3D:
    def __init__(self, x, y, z, pid):
        self.x = x
        self.y = y
        self.z = z
        self.id = pid


class BoundingBox:
    def __init__(self, k1, k2, k3, k4):
        self.k1 = k1
        self.k2 = k2
        self.k3 = k3
        self.k4 = k4


class ObjectDetection:
    def __init__(self, oid, bbox):
        self.id = oid
        self.bbox = bbox


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
    xs = [bbox.k1[0], bbox.k2[0], bbox.k3[0], bbox.k4[0]]
    ys = [bbox.k1[1], bbox.k2[1], bbox.k3[1], bbox.k4[1]]
    return (min(xs) <= pt[0] <= max(xs)) and (min(ys) <= pt[1] <= max(ys))


class FusionNode(Node):
    def __init__(self):
        super().__init__("fusion_node")

        self.bridge = CvBridge()
        self.K = None
        self.latest_image = None
        self.latest_points = None

        # TF listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Define frame ids 
        self.camera_frame = "carla/hero/rgb_front"
        self.lidar_frame = "carla/hero/lidar"
        self.world_frame = "map"

        # Subscribers
        self.create_subscription(CameraInfo, "/carla/hero/rgb_front/camera_info", self.camera_info_cb, 10)
        self.create_subscription(Image, "/carla/hero/rgb_front/image", self.image_cb, 10)
        self.create_subscription(PointCloud2, "/carla/hero/lidar", self.lidar_cb, 10)

        # Example detection (just for testing)
        self.detected_objects = [
            ObjectDetection(0, BoundingBox(
                (600, 300), (650, 300), (650, 350), (600, 350)
            ))
        ]

    def get_lidar_to_camera_tf(self):
        try:
            # Transform lidar → camera
            tf_msg = self.tf_buffer.lookup_transform(
                self.camera_frame,   # target
                self.lidar_frame,    # source
                rclpy.time.Time()
            )

            t = tf_msg.transform.translation
            q = tf_msg.transform.rotation

            T = tf_transformations.translation_matrix([t.x, t.y, t.z])
            R = tf_transformations.quaternion_matrix([q.x, q.y, q.z, q.w])
            return np.dot(T, R)  # 4x4 extrinsic matrix

        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return None

    def camera_info_cb(self, msg: CameraInfo):
        self.K = np.array(msg.k).reshape(3, 3)

    def image_cb(self, msg: Image):
        self.latest_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

    def lidar_cb(self, msg: PointCloud2):
        points = []
        for i, p in enumerate(pc2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True)):
            points.append(Point3D(p[0], p[1], p[2], i))
        self.latest_points = points

        if self.K is not None and self.latest_image is not None:
            T_lidar_to_cam = self.get_lidar_to_camera_tf()
            if T_lidar_to_cam is not None:
                self.run_fusion(T_lidar_to_cam)

    def run_fusion(self, T_lidar_to_cam):
        img = self.latest_image.copy()

        for obj in self.detected_objects:
            min_z = float("inf")

            cv2.polylines(img, [np.array([obj.bbox.k1, obj.bbox.k2, obj.bbox.k3, obj.bbox.k4], np.int32)],
                          isClosed=True, color=(0, 255, 0), thickness=2)

            for p in self.latest_points:
                p_cam = transform_point((p.x, p.y, p.z), T_lidar_to_cam)
                if p_cam[2] <= 0:
                    continue

                uv = project_to_image(p_cam, self.K)
                u, v = int(uv[0]), int(uv[1])

                if 0 <= u < img.shape[1] and 0 <= v < img.shape[0]:
                    if point_inside_bbox((u, v), obj.bbox):
                        cv2.circle(img, (u, v), 2, (0, 0, 255), -1)
                        min_z = min(min_z, p_cam[2])
                    else:
                        cv2.circle(img, (u, v), 1, (255, 0, 0), -1)

            if min_z < float("inf"):
                cv2.putText(img, f"Depth: {min_z:.2f} m",
                            (obj.bbox.k1[0], obj.bbox.k1[1] - 10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 255), 2)

        cv2.imshow("Fusion", img)
        cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)
    node = FusionNode()
    rclpy.spin(node)
    node.destroy_node()
    cv2.destroyAllWindows()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
