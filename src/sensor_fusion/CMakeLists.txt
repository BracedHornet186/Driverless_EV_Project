cmake_minimum_required(VERSION 3.8)
project(sensor_fusion)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Include C++ "include" directory
include_directories(
  include
  launch
  )

# # Create C++ executable
# add_executable(cpp_executable src/cpp_node.cpp)
# ament_target_dependencies(cpp_executable rclcpp)

# # Install C++ executables
# install(TARGETS
#   cpp_executable
#   DESTINATION lib/${PROJECT_NAME}
# )

ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  sensor_fusion/fusion_node.py
  sensor_fusion/yolo_detector.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
