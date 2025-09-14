// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/ObjectDetections.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/object_detections__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `detections`
#include "perception_msgs/msg/detail/object_detection__functions.h"

bool
perception_msgs__msg__ObjectDetections__init(perception_msgs__msg__ObjectDetections * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    perception_msgs__msg__ObjectDetections__fini(msg);
    return false;
  }
  // detections
  if (!perception_msgs__msg__ObjectDetection__Sequence__init(&msg->detections, 0)) {
    perception_msgs__msg__ObjectDetections__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__msg__ObjectDetections__fini(perception_msgs__msg__ObjectDetections * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // detections
  perception_msgs__msg__ObjectDetection__Sequence__fini(&msg->detections);
}

bool
perception_msgs__msg__ObjectDetections__are_equal(const perception_msgs__msg__ObjectDetections * lhs, const perception_msgs__msg__ObjectDetections * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // detections
  if (!perception_msgs__msg__ObjectDetection__Sequence__are_equal(
      &(lhs->detections), &(rhs->detections)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__ObjectDetections__copy(
  const perception_msgs__msg__ObjectDetections * input,
  perception_msgs__msg__ObjectDetections * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // detections
  if (!perception_msgs__msg__ObjectDetection__Sequence__copy(
      &(input->detections), &(output->detections)))
  {
    return false;
  }
  return true;
}

perception_msgs__msg__ObjectDetections *
perception_msgs__msg__ObjectDetections__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__ObjectDetections * msg = (perception_msgs__msg__ObjectDetections *)allocator.allocate(sizeof(perception_msgs__msg__ObjectDetections), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__ObjectDetections));
  bool success = perception_msgs__msg__ObjectDetections__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__ObjectDetections__destroy(perception_msgs__msg__ObjectDetections * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__ObjectDetections__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__ObjectDetections__Sequence__init(perception_msgs__msg__ObjectDetections__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__ObjectDetections * data = NULL;

  if (size) {
    data = (perception_msgs__msg__ObjectDetections *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__ObjectDetections), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__ObjectDetections__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__ObjectDetections__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
perception_msgs__msg__ObjectDetections__Sequence__fini(perception_msgs__msg__ObjectDetections__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      perception_msgs__msg__ObjectDetections__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

perception_msgs__msg__ObjectDetections__Sequence *
perception_msgs__msg__ObjectDetections__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__ObjectDetections__Sequence * array = (perception_msgs__msg__ObjectDetections__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__ObjectDetections__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__ObjectDetections__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__ObjectDetections__Sequence__destroy(perception_msgs__msg__ObjectDetections__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__ObjectDetections__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__ObjectDetections__Sequence__are_equal(const perception_msgs__msg__ObjectDetections__Sequence * lhs, const perception_msgs__msg__ObjectDetections__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__ObjectDetections__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__ObjectDetections__Sequence__copy(
  const perception_msgs__msg__ObjectDetections__Sequence * input,
  perception_msgs__msg__ObjectDetections__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__ObjectDetections);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    perception_msgs__msg__ObjectDetections * data =
      (perception_msgs__msg__ObjectDetections *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__ObjectDetections__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__ObjectDetections__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_msgs__msg__ObjectDetections__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
