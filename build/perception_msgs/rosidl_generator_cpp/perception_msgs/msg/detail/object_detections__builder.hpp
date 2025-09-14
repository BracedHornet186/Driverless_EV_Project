// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/ObjectDetections.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTIONS__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_msgs/msg/detail/object_detections__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_ObjectDetections_detections
{
public:
  explicit Init_ObjectDetections_detections(::perception_msgs::msg::ObjectDetections & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::ObjectDetections detections(::perception_msgs::msg::ObjectDetections::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::ObjectDetections msg_;
};

class Init_ObjectDetections_header
{
public:
  Init_ObjectDetections_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectDetections_detections header(::perception_msgs::msg::ObjectDetections::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ObjectDetections_detections(msg_);
  }

private:
  ::perception_msgs::msg::ObjectDetections msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::ObjectDetections>()
{
  return perception_msgs::msg::builder::Init_ObjectDetections_header();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTIONS__BUILDER_HPP_
