// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/ObjectDetections.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTIONS__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'detections'
#include "perception_msgs/msg/detail/object_detection__struct.h"

/// Struct defined in msg/ObjectDetections in the package perception_msgs.
typedef struct perception_msgs__msg__ObjectDetections
{
  std_msgs__msg__Header header;
  perception_msgs__msg__ObjectDetection__Sequence detections;
} perception_msgs__msg__ObjectDetections;

// Struct for a sequence of perception_msgs__msg__ObjectDetections.
typedef struct perception_msgs__msg__ObjectDetections__Sequence
{
  perception_msgs__msg__ObjectDetections * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__ObjectDetections__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTIONS__STRUCT_H_
