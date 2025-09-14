// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from perception_msgs:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "perception_msgs/msg/detail/object_detection__rosidl_typesupport_introspection_c.h"
#include "perception_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "perception_msgs/msg/detail/object_detection__functions.h"
#include "perception_msgs/msg/detail/object_detection__struct.h"


// Include directives for member types
// Member `bbox`
#include "perception_msgs/msg/bounding_box.h"
// Member `bbox`
#include "perception_msgs/msg/detail/bounding_box__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  perception_msgs__msg__ObjectDetection__init(message_memory);
}

void perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_fini_function(void * message_memory)
{
  perception_msgs__msg__ObjectDetection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_member_array[2] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__ObjectDetection, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__ObjectDetection, bbox),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_members = {
  "perception_msgs__msg",  // message namespace
  "ObjectDetection",  // message name
  2,  // number of fields
  sizeof(perception_msgs__msg__ObjectDetection),
  perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_member_array,  // message members
  perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle = {
  0,
  &perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_perception_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, msg, ObjectDetection)() {
  perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, msg, BoundingBox)();
  if (!perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle.typesupport_identifier) {
    perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &perception_msgs__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
