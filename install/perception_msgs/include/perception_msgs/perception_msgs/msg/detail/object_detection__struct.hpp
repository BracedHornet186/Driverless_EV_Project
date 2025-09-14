// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'bbox'
#include "perception_msgs/msg/detail/bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__ObjectDetection __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__ObjectDetection __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectDetection_
{
  using Type = ObjectDetection_<ContainerAllocator>;

  explicit ObjectDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bbox(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  explicit ObjectDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bbox(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _bbox_type =
    perception_msgs::msg::BoundingBox_<ContainerAllocator>;
  _bbox_type bbox;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__bbox(
    const perception_msgs::msg::BoundingBox_<ContainerAllocator> & _arg)
  {
    this->bbox = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::msg::ObjectDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::ObjectDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::ObjectDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::ObjectDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__ObjectDetection
    std::shared_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__ObjectDetection
    std::shared_ptr<perception_msgs::msg::ObjectDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectDetection_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->bbox != other.bbox) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectDetection_

// alias to use template instance with default allocator
using ObjectDetection =
  perception_msgs::msg::ObjectDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__STRUCT_HPP_
