// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bbox'
#include "perception_msgs/msg/detail/bounding_box__struct.h"

/// Struct defined in msg/ObjectDetection in the package perception_msgs.
typedef struct perception_msgs__msg__ObjectDetection
{
  int32_t id;
  perception_msgs__msg__BoundingBox bbox;
} perception_msgs__msg__ObjectDetection;

// Struct for a sequence of perception_msgs__msg__ObjectDetection.
typedef struct perception_msgs__msg__ObjectDetection__Sequence
{
  perception_msgs__msg__ObjectDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__ObjectDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__STRUCT_H_
