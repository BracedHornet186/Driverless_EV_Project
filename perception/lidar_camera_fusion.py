import pyrealsense2 as rs
import numpy as np
import cv2
from get_realsense_intrinsics import get_realsense_intrinsics

class Point3D:
    def __init__(self, x, y, z, pid):
        self.x = x
        self.y = y
        self.z = z
        self.id = pid

class BoundingBox:
    def __init__(self, k1, k2, k3, k4):
        self.k1 = k1  # (x, y)
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
    """Check if point lies inside an axis-aligned bounding box"""
    xs = [bbox.k1[0], bbox.k2[0], bbox.k3[0], bbox.k4[0]]
    ys = [bbox.k1[1], bbox.k2[1], bbox.k3[1], bbox.k4[1]]
    return (min(xs) <= pt[0] <= max(xs)) and (min(ys) <= pt[1] <= max(ys))

def main():

    # Camera intrinsic matrix
    intrinsics = get_realsense_intrinsics()
    K = intrinsics["color"]["matrix"]

    # Extrinsic transformation (LiDAR -> Camera)
    T_lidar_to_cam = np.array([
        [1, 0, 0, 0.1],
        [0, 1, 0, 0.0],
        [0, 0, 1, 0.2],
        [0, 0, 0, 1]
    ])

    # Example LiDAR points
    lidar_points = [
        Point3D(5.0, 1.0, 2.0, 0),
        Point3D(6.0, 1.2, 2.1, 1),
        Point3D(4.5, 0.5, 1.8, 2)
    ]

    # Example detected objects
    detected_objects = [
        ObjectDetection(0, BoundingBox(
            (600, 300), (650, 300), (650, 350), (600, 350)
        ))
    ]

    # Algorithm 1 implementation
    for obj in detected_objects:
        min_z = float("inf")

        for p in lidar_points:
            # Transform point to camera frame
            p_cam = transform_point((p.x, p.y, p.z), T_lidar_to_cam)

            # Skip if behind the camera
            if p_cam[2] <= 0:
                continue

            # Project to pixel coordinates
            uv = project_to_image(p_cam, K)

            # Check if inside bounding box
            if point_inside_bbox(uv, obj.bbox):
                min_z = min(min_z, p_cam[2])

        if min_z < float("inf"):
            print(f"Object {obj.id} depth: {min_z:.3f} m")
        else:
            print(f"Object {obj.id} depth: Not found")

if __name__ == "__main__":
    main()
