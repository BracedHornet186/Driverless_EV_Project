// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from perception_msgs:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "perception_msgs/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'k1'
// Member 'k2'
// Member 'k3'
// Member 'k4'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace perception_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BoundingBox & msg,
  std::ostream & out)
{
  out << "{";
  // member: k1
  {
    out << "k1: ";
    to_flow_style_yaml(msg.k1, out);
    out << ", ";
  }

  // member: k2
  {
    out << "k2: ";
    to_flow_style_yaml(msg.k2, out);
    out << ", ";
  }

  // member: k3
  {
    out << "k3: ";
    to_flow_style_yaml(msg.k3, out);
    out << ", ";
  }

  // member: k4
  {
    out << "k4: ";
    to_flow_style_yaml(msg.k4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoundingBox & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: k1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "k1:\n";
    to_block_style_yaml(msg.k1, out, indentation + 2);
  }

  // member: k2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "k2:\n";
    to_block_style_yaml(msg.k2, out, indentation + 2);
  }

  // member: k3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "k3:\n";
    to_block_style_yaml(msg.k3, out, indentation + 2);
  }

  // member: k4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "k4:\n";
    to_block_style_yaml(msg.k4, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoundingBox & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace perception_msgs

namespace rosidl_generator_traits
{

[[deprecated("use perception_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const perception_msgs::msg::BoundingBox & msg,
  std::ostream & out, size_t indentation = 0)
{
  perception_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use perception_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const perception_msgs::msg::BoundingBox & msg)
{
  return perception_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<perception_msgs::msg::BoundingBox>()
{
  return "perception_msgs::msg::BoundingBox";
}

template<>
inline const char * name<perception_msgs::msg::BoundingBox>()
{
  return "perception_msgs/msg/BoundingBox";
}

template<>
struct has_fixed_size<perception_msgs::msg::BoundingBox>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<perception_msgs::msg::BoundingBox>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<perception_msgs::msg::BoundingBox>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PERCEPTION_MSGS__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
