#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
import cv2
import numpy as np
from ultralytics import YOLO

# Custom msgs
from perception_msgs.msg import ObjectDetections, ObjectDetection, BoundingBox
from geometry_msgs.msg import Point
from std_msgs.msg import Header


class YoloDetectorPublisher(Node):
    def __init__(self):
        super().__init__("yolo_detector_publisher")

        # Load YOLOv8 model (pre-trained on COCO)
        self.model = YOLO("src/sensor_fusion/config/yolov8n.pt")

        # Bridge for ROS <-> OpenCV conversion
        self.bridge = CvBridge()

        # Subscriptions
        self.image_sub = self.create_subscription(
            Image, "/carla/hero/rgb_front/image", self.image_callback, 10
        )
        self.camera_info_sub = self.create_subscription(
            CameraInfo, "/carla/hero/rgb_front/camera_info", self.camera_info_callback, 10
        )

        # Publishers
        self.annotated_pub = self.create_publisher(Image, "/yolo/annotated_image", 10)
        self.detections_pub = self.create_publisher(ObjectDetections, "/detections", 10)

        # Camera intrinsics placeholder
        self.K = None

    def camera_info_callback(self, msg: CameraInfo):
        """Store camera intrinsic matrix"""
        K = np.array(msg.k).reshape(3, 3)
        self.K = K

    def image_callback(self, msg: Image):
        """Run YOLO detection on incoming camera images"""
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        # Run inference
        results = self.model(frame)

        # Annotated image
        annotated = results[0].plot()

        # Convert back to ROS Image and publish
        annotated_msg = self.bridge.cv2_to_imgmsg(annotated, "bgr8")
        annotated_msg.header = msg.header
        self.annotated_pub.publish(annotated_msg)

        # Convert detections into ObjectDetections msg
        detections_msg = ObjectDetections()
        detections_msg.header = Header()
        detections_msg.header.stamp = self.get_clock().now().to_msg()

        for i, box in enumerate(results[0].boxes):
            cls_id = int(box.cls.cpu().numpy()[0])
            conf = float(box.conf.cpu().numpy()[0])

            # COCO: 2 = car, 3 = motorcycle
            if cls_id in [2, 3] and conf > 0.5:
                x1, y1, x2, y2 = box.xyxy[0].cpu().numpy()

                det_msg = ObjectDetection()
                det_msg.id = i  # assign index as ID

                bbox = BoundingBox()
                bbox.k1 = Point(x=float(x1), y=float(y1), z=0.0)
                bbox.k2 = Point(x=float(x2), y=float(y1), z=0.0)
                bbox.k3 = Point(x=float(x2), y=float(y2), z=0.0)
                bbox.k4 = Point(x=float(x1), y=float(y2), z=0.0)

                det_msg.bbox = bbox
                detections_msg.detections.append(det_msg)

                label = "Car" if cls_id == 2 else "Motorcycle"
                self.get_logger().info(
                    f"{label} detected: ID={i}, conf={conf:.2f}, box=({x1:.1f}, {y1:.1f}), ({x2:.1f}, {y2:.1f})"
                )


        # Publish detections
        if detections_msg.detections:
            self.detections_pub.publish(detections_msg)
            self.get_logger().info(f"Published {len(detections_msg.detections)} detections")


def main(args=None):
    rclpy.init(args=args)
    node = YoloDetectorPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()