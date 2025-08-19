from ouster.sdk import core
from ouster.sdk import sensor

# Set the hostname of the Ouster sensor
hostname = "os-122507000193.local"
# create empty config
config = core.SensorConfig()

# set the values that you need: see sensor documentation for param meanings
config.operating_mode = core.OperatingMode.OPERATING_NORMAL
config.lidar_mode = core.LidarMode.MODE_1024x10
config.udp_port_lidar = 7502
config.udp_port_imu = 7503

# set the config on sensor, using appropriate flags
sensor.set_config(hostname, config, persist=True, udp_dest_auto=True)

# Get metadata from the sensor
source = sensor.SensorScanner(hostname, config)
metadata = source.get_metadata(hostname)
if metadata is None:
    print("Failed to retrieve metadata from the sensor.")
else:    
    # print some useful info from metadata
    print("Retrieved metadata:")
    print(f"  serial no:        {metadata.sn}")
    print(f"  firmware version: {metadata.fw_rev}")
    print(f"  product line:     {metadata.prod_line}")
    print(f"  lidar mode:       {metadata.config.lidar_mode}")