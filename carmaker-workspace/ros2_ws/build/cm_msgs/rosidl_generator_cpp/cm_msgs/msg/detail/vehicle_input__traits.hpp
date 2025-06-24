// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cm_msgs:msg/VehicleInput.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__TRAITS_HPP_
#define CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cm_msgs/msg/detail/vehicle_input__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleInput & msg,
  std::ostream & out)
{
  out << "{";
  // member: gas
  {
    out << "gas: ";
    rosidl_generator_traits::value_to_yaml(msg.gas, out);
    out << ", ";
  }

  // member: brake
  {
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gas: ";
    rosidl_generator_traits::value_to_yaml(msg.gas, out);
    out << "\n";
  }

  // member: brake
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleInput & msg, bool use_flow_style = false)
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

}  // namespace cm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cm_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cm_msgs::msg::VehicleInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  cm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cm_msgs::msg::VehicleInput & msg)
{
  return cm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cm_msgs::msg::VehicleInput>()
{
  return "cm_msgs::msg::VehicleInput";
}

template<>
inline const char * name<cm_msgs::msg::VehicleInput>()
{
  return "cm_msgs/msg/VehicleInput";
}

template<>
struct has_fixed_size<cm_msgs::msg::VehicleInput>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cm_msgs::msg::VehicleInput>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cm_msgs::msg::VehicleInput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__TRAITS_HPP_
