import pyzed.sl as sl
import cv2
import numpy as np

def get_zed_intrinsics():
    """
    Initialize ZED camera, fetch color intrinsics, and
    return them along with NumPy intrinsic matrices.

    Returns:
        numpy.ndarray: Shape (3, 3). The camera intrinsic matrix in pixel units:
            [[fx,  0, cx],
             [ 0, fy, cy],
             [ 0,  0,  1]]
    """
    # Create a ZED camera object
    zed = sl.Camera()

    # Set configuration parameters
    init_params = sl.InitParameters()
    init_params.camera_resolution = sl.RESOLUTION.VGA  # Set camera resolution ('VGA', 'HD720', 'HD1080', 'HD2K')
    init_params.camera_fps = 30  # Set camera FPS
    init_params.depth_mode = sl.DEPTH_MODE.NEURAL  # Set depth mode

    # Open the camera
    err = zed.open(init_params)
    if err != sl.ERROR_CODE.SUCCESS:
        print(f"Error opening ZED camera: {repr(err)}")
        exit(1)

    # Get camera information
    camera_intrinsics = zed.get_camera_information().camera_configuration.calibration_parameters.left_cam
    zed.close()

    return np.array([
        [camera_intrinsics.fx, 0, camera_intrinsics.cx],
        [0, camera_intrinsics.fy, camera_intrinsics.cy],
        [0, 0, 1]
    ])
if __name__ == "__main__":
    intrinsic_matrix = get_zed_intrinsics()
    print("Intrinsics:\n", intrinsic_matrix)