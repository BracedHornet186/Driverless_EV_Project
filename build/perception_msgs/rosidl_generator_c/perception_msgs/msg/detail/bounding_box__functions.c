// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/bounding_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `k1`
// Member `k2`
// Member `k3`
// Member `k4`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
perception_msgs__msg__BoundingBox__init(perception_msgs__msg__BoundingBox * msg)
{
  if (!msg) {
    return false;
  }
  // k1
  if (!geometry_msgs__msg__Point__init(&msg->k1)) {
    perception_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  // k2
  if (!geometry_msgs__msg__Point__init(&msg->k2)) {
    perception_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  // k3
  if (!geometry_msgs__msg__Point__init(&msg->k3)) {
    perception_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  // k4
  if (!geometry_msgs__msg__Point__init(&msg->k4)) {
    perception_msgs__msg__BoundingBox__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__msg__BoundingBox__fini(perception_msgs__msg__BoundingBox * msg)
{
  if (!msg) {
    return;
  }
  // k1
  geometry_msgs__msg__Point__fini(&msg->k1);
  // k2
  geometry_msgs__msg__Point__fini(&msg->k2);
  // k3
  geometry_msgs__msg__Point__fini(&msg->k3);
  // k4
  geometry_msgs__msg__Point__fini(&msg->k4);
}

bool
perception_msgs__msg__BoundingBox__are_equal(const perception_msgs__msg__BoundingBox * lhs, const perception_msgs__msg__BoundingBox * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // k1
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->k1), &(rhs->k1)))
  {
    return false;
  }
  // k2
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->k2), &(rhs->k2)))
  {
    return false;
  }
  // k3
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->k3), &(rhs->k3)))
  {
    return false;
  }
  // k4
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->k4), &(rhs->k4)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__BoundingBox__copy(
  const perception_msgs__msg__BoundingBox * input,
  perception_msgs__msg__BoundingBox * output)
{
  if (!input || !output) {
    return false;
  }
  // k1
  if (!geometry_msgs__msg__Point__copy(
      &(input->k1), &(output->k1)))
  {
    return false;
  }
  // k2
  if (!geometry_msgs__msg__Point__copy(
      &(input->k2), &(output->k2)))
  {
    return false;
  }
  // k3
  if (!geometry_msgs__msg__Point__copy(
      &(input->k3), &(output->k3)))
  {
    return false;
  }
  // k4
  if (!geometry_msgs__msg__Point__copy(
      &(input->k4), &(output->k4)))
  {
    return false;
  }
  return true;
}

perception_msgs__msg__BoundingBox *
perception_msgs__msg__BoundingBox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__BoundingBox * msg = (perception_msgs__msg__BoundingBox *)allocator.allocate(sizeof(perception_msgs__msg__BoundingBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__BoundingBox));
  bool success = perception_msgs__msg__BoundingBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__BoundingBox__destroy(perception_msgs__msg__BoundingBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__BoundingBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__BoundingBox__Sequence__init(perception_msgs__msg__BoundingBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__BoundingBox * data = NULL;

  if (size) {
    data = (perception_msgs__msg__BoundingBox *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__BoundingBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__BoundingBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__BoundingBox__fini(&data[i - 1]);
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
perception_msgs__msg__BoundingBox__Sequence__fini(perception_msgs__msg__BoundingBox__Sequence * array)
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
      perception_msgs__msg__BoundingBox__fini(&array->data[i]);
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

perception_msgs__msg__BoundingBox__Sequence *
perception_msgs__msg__BoundingBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__BoundingBox__Sequence * array = (perception_msgs__msg__BoundingBox__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__BoundingBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__BoundingBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__BoundingBox__Sequence__destroy(perception_msgs__msg__BoundingBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__BoundingBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__BoundingBox__Sequence__are_equal(const perception_msgs__msg__BoundingBox__Sequence * lhs, const perception_msgs__msg__BoundingBox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__BoundingBox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__BoundingBox__Sequence__copy(
  const perception_msgs__msg__BoundingBox__Sequence * input,
  perception_msgs__msg__BoundingBox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__BoundingBox);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    perception_msgs__msg__BoundingBox * data =
      (perception_msgs__msg__BoundingBox *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__BoundingBox__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__BoundingBox__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_msgs__msg__BoundingBox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
