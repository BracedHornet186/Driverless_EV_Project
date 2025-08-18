import pyzed.sl as sl
import cv2

def main():
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
    camera_info = zed.get_camera_information()
    print(f"Camera Intrinsics:\n{camera_info.camera_configuration.calibration_parameters.left_cam.fx}")

    # Create a Mat object to store images
    image = sl.Mat()

    # Capture and display frames
    print("Press 'q' to exit.")
    while True:
        # Grab a new frame from the ZED
        if zed.grab() == sl.ERROR_CODE.SUCCESS:
            # Retrieve image
            zed.retrieve_image(image, sl.VIEW.LEFT)

            # Convert to OpenCV format and display
            cv_image = image.get_data()
            cv2.imshow("ZED Camera", cv_image)

            # Check for 'q' key press to exit
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

    # Close the camera
    zed.close()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()