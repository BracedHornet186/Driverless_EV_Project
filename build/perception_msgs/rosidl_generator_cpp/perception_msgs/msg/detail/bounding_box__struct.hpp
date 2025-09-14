// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'k1'
// Member 'k2'
// Member 'k3'
// Member 'k4'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__BoundingBox __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__BoundingBox __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoundingBox_
{
  using Type = BoundingBox_<ContainerAllocator>;

  explicit BoundingBox_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : k1(_init),
    k2(_init),
    k3(_init),
    k4(_init)
  {
    (void)_init;
  }

  explicit BoundingBox_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : k1(_alloc, _init),
    k2(_alloc, _init),
    k3(_alloc, _init),
    k4(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _k1_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _k1_type k1;
  using _k2_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _k2_type k2;
  using _k3_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _k3_type k3;
  using _k4_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _k4_type k4;

  // setters for named parameter idiom
  Type & set__k1(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->k1 = _arg;
    return *this;
  }
  Type & set__k2(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->k2 = _arg;
    return *this;
  }
  Type & set__k3(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->k3 = _arg;
    return *this;
  }
  Type & set__k4(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->k4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::msg::BoundingBox_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::BoundingBox_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::BoundingBox_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::BoundingBox_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__BoundingBox
    std::shared_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__BoundingBox
    std::shared_ptr<perception_msgs::msg::BoundingBox_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoundingBox_ & other) const
  {
    if (this->k1 != other.k1) {
      return false;
    }
    if (this->k2 != other.k2) {
      return false;
    }
    if (this->k3 != other.k3) {
      return false;
    }
    if (this->k4 != other.k4) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoundingBox_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoundingBox_

// alias to use template instance with default allocator
using BoundingBox =
  perception_msgs::msg::BoundingBox_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__STRUCT_HPP_
