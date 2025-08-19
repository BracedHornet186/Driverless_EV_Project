import numpy as np
from ouster.sdk import core, sensor

def get_lidar_points(hostname: str,
                     range_min: float) -> np.ndarray:
    """
    Connect to Ouster LiDAR and return XYZ points as NumPy array (N, 3).

    Args:
        hostname (str): Sensor hostname or IP.
        range_min (float): Minimum valid range in meters.

    Returns:
        np.ndarray: LiDAR points in shape (N, 3), in sensor frame.
    """

    # Configure sensor
    config = core.SensorConfig()
    config.operating_mode = core.OperatingMode.OPERATING_NORMAL
    config.lidar_mode = core.LidarMode.MODE_1024x10,
    config.udp_port_lidar = 7502
    config.udp_port_imu = 7503

    # Apply config
    sensor.set_config(hostname, config, persist=True, udp_dest_auto=True)

    # Open data stream
    source = sensor.SensorScanner(hostname, config)
    metadata = source.get_metadata()

    # Get a single scan
    scan = next(iter(source))[0]
    assert scan is not None, "No LiDAR scan received!"

    # Destagger range and compute XYZ
    range_destaggered = core.destagger(metadata, scan.field(core.ChanField.RANGE))
    xyzlut = core.XYZLut(metadata)
    xyz_destaggered = core.destagger(metadata, xyzlut(scan))

    # Filter out points closer than range_min
    mask = range_destaggered > (range_min * 1000)   # convert m → mm
    xyz_filtered = xyz_destaggered * mask[:, :, np.newaxis]

    # Reshape to (N, 3) and remove all-zero rows
    points = xyz_filtered.reshape(-1, 3)
    points = points[~np.all(points == 0, axis=1)]

    # Close connection
    source.close()

    return points

if __name__ == "__main__":
    points = get_lidar_points(hostname="os-122507000193.local", range_min=0.5)