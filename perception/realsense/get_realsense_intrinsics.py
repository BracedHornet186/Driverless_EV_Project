import pyrealsense2 as rs
import numpy as np

def get_realsense_intrinsics():
    """
    Initialize Intel RealSense camera, fetch color & depth intrinsics,
    and return them along with NumPy intrinsic matrices.

    Returns:
        dict: {
            "color": {
                "intrinsics": rs.intrinsics,
                "matrix": np.ndarray (3x3)
            },
            "depth": {
                "intrinsics": rs.intrinsics,
                "matrix": np.ndarray (3x3)
            }
        }
    """
    # Configure depth and color streams
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
    config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)

    try:
        # Start streaming
        profile = pipeline.start(config)

        # Get stream profiles
        color_stream_profile = profile.get_stream(rs.stream.color)
        depth_stream_profile = profile.get_stream(rs.stream.depth)

        # Get intrinsics
        color_intrinsics = color_stream_profile.as_video_stream_profile().get_intrinsics()
        depth_intrinsics = depth_stream_profile.as_video_stream_profile().get_intrinsics()

        # Convert to numpy intrinsic matrix
        color_matrix = np.array([
            [color_intrinsics.fx, 0, color_intrinsics.ppx],
            [0, color_intrinsics.fy, color_intrinsics.ppy],
            [0, 0, 1]
        ])

        depth_matrix = np.array([
            [depth_intrinsics.fx, 0, depth_intrinsics.ppx],
            [0, depth_intrinsics.fy, depth_intrinsics.ppy],
            [0, 0, 1]
        ])

    finally:
        # Always stop pipeline
        pipeline.stop()    
        
        return {
            "color": {
                "intrinsics": color_intrinsics,
                "matrix": color_matrix
            },
            "depth": {
                "intrinsics": depth_intrinsics,
                "matrix": depth_matrix
            }
        }

if __name__ == "__main__":
    intrinsics = get_realsense_intrinsics()
    print("Color Camera Matrix:\n", intrinsics["color"]["matrix"])
    print("Depth Camera Matrix:\n", intrinsics["depth"]["matrix"])
