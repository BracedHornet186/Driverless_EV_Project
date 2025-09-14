// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "perception_msgs/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_k4
{
public:
  explicit Init_BoundingBox_k4(::perception_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::BoundingBox k4(::perception_msgs::msg::BoundingBox::_k4_type arg)
  {
    msg_.k4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_k3
{
public:
  explicit Init_BoundingBox_k3(::perception_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_k4 k3(::perception_msgs::msg::BoundingBox::_k3_type arg)
  {
    msg_.k3 = std::move(arg);
    return Init_BoundingBox_k4(msg_);
  }

private:
  ::perception_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_k2
{
public:
  explicit Init_BoundingBox_k2(::perception_msgs::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_k3 k2(::perception_msgs::msg::BoundingBox::_k2_type arg)
  {
    msg_.k2 = std::move(arg);
    return Init_BoundingBox_k3(msg_);
  }

private:
  ::perception_msgs::msg::BoundingBox msg_;
};

class Init_BoundingBox_k1
{
public:
  Init_BoundingBox_k1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_k2 k1(::perception_msgs::msg::BoundingBox::_k1_type arg)
  {
    msg_.k1 = std::move(arg);
    return Init_BoundingBox_k2(msg_);
  }

private:
  ::perception_msgs::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::BoundingBox>()
{
  return perception_msgs::msg::builder::Init_BoundingBox_k1();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
