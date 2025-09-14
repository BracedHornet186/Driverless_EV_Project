// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from perception_msgs:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__FUNCTIONS_H_
#define PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "perception_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "perception_msgs/msg/detail/object_detection__struct.h"

/// Initialize msg/ObjectDetection message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * perception_msgs__msg__ObjectDetection
 * )) before or use
 * perception_msgs__msg__ObjectDetection__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__msg__ObjectDetection__init(perception_msgs__msg__ObjectDetection * msg);

/// Finalize msg/ObjectDetection message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__msg__ObjectDetection__fini(perception_msgs__msg__ObjectDetection * msg);

/// Create msg/ObjectDetection message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * perception_msgs__msg__ObjectDetection__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
perception_msgs__msg__ObjectDetection *
perception_msgs__msg__ObjectDetection__create();

/// Destroy msg/ObjectDetection message.
/**
 * It calls
 * perception_msgs__msg__ObjectDetection__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__msg__ObjectDetection__destroy(perception_msgs__msg__ObjectDetection * msg);

/// Check for msg/ObjectDetection message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__msg__ObjectDetection__are_equal(const perception_msgs__msg__ObjectDetection * lhs, const perception_msgs__msg__ObjectDetection * rhs);

/// Copy a msg/ObjectDetection message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__msg__ObjectDetection__copy(
  const perception_msgs__msg__ObjectDetection * input,
  perception_msgs__msg__ObjectDetection * output);

/// Initialize array of msg/ObjectDetection messages.
/**
 * It allocates the memory for the number of elements and calls
 * perception_msgs__msg__ObjectDetection__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__msg__ObjectDetection__Sequence__init(perception_msgs__msg__ObjectDetection__Sequence * array, size_t size);

/// Finalize array of msg/ObjectDetection messages.
/**
 * It calls
 * perception_msgs__msg__ObjectDetection__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__msg__ObjectDetection__Sequence__fini(perception_msgs__msg__ObjectDetection__Sequence * array);

/// Create array of msg/ObjectDetection messages.
/**
 * It allocates the memory for the array and calls
 * perception_msgs__msg__ObjectDetection__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
perception_msgs__msg__ObjectDetection__Sequence *
perception_msgs__msg__ObjectDetection__Sequence__create(size_t size);

/// Destroy array of msg/ObjectDetection messages.
/**
 * It calls
 * perception_msgs__msg__ObjectDetection__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__msg__ObjectDetection__Sequence__destroy(perception_msgs__msg__ObjectDetection__Sequence * array);

/// Check for msg/ObjectDetection message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__msg__ObjectDetection__Sequence__are_equal(const perception_msgs__msg__ObjectDetection__Sequence * lhs, const perception_msgs__msg__ObjectDetection__Sequence * rhs);

/// Copy an array of msg/ObjectDetection messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__msg__ObjectDetection__Sequence__copy(
  const perception_msgs__msg__ObjectDetection__Sequence * input,
  perception_msgs__msg__ObjectDetection__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__FUNCTIONS_H_
