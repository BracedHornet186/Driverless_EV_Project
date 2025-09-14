// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from perception_msgs:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__TRAITS_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "perception_msgs/msg/detail/object_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'bbox'
#include "perception_msgs/msg/detail/bounding_box__traits.hpp"

namespace perception_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: bbox
  {
    out << "bbox: ";
    to_flow_style_yaml(msg.bbox, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: bbox
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox:\n";
    to_block_style_yaml(msg.bbox, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectDetection & msg, bool use_flow_style = false)
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
  const perception_msgs::msg::ObjectDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  perception_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use perception_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const perception_msgs::msg::ObjectDetection & msg)
{
  return perception_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<perception_msgs::msg::ObjectDetection>()
{
  return "perception_msgs::msg::ObjectDetection";
}

template<>
inline const char * name<perception_msgs::msg::ObjectDetection>()
{
  return "perception_msgs/msg/ObjectDetection";
}

template<>
struct has_fixed_size<perception_msgs::msg::ObjectDetection>
  : std::integral_constant<bool, has_fixed_size<perception_msgs::msg::BoundingBox>::value> {};

template<>
struct has_bounded_size<perception_msgs::msg::ObjectDetection>
  : std::integral_constant<bool, has_bounded_size<perception_msgs::msg::BoundingBox>::value> {};

template<>
struct is_message<perception_msgs::msg::ObjectDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PERCEPTION_MSGS__MSG__DETAIL__OBJECT_DETECTION__TRAITS_HPP_
