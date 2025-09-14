// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_msgs/msg/detail/object_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_ObjectDetection_bbox
{
public:
  explicit Init_ObjectDetection_bbox(::perception_msgs::msg::ObjectDetection & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::ObjectDetection bbox(::perception_msgs::msg::ObjectDetection::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::ObjectDetection msg_;
};

class Init_ObjectDetection_id
{
public:
  Init_ObjectDetection_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectDetection_bbox id(::perception_msgs::msg::ObjectDetection::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ObjectDetection_bbox(msg_);
  }

private:
  ::perception_msgs::msg::ObjectDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::ObjectDetection>()
{
  return perception_msgs::msg::builder::Init_ObjectDetection_id();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__BUILDER_HPP_
