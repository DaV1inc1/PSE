// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:msg/VehicleInput.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__BUILDER_HPP_
#define CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/msg/detail/vehicle_input__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleInput_brake
{
public:
  explicit Init_VehicleInput_brake(::cm_msgs::msg::VehicleInput & msg)
  : msg_(msg)
  {}
  ::cm_msgs::msg::VehicleInput brake(::cm_msgs::msg::VehicleInput::_brake_type arg)
  {
    msg_.brake = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::msg::VehicleInput msg_;
};

class Init_VehicleInput_gas
{
public:
  Init_VehicleInput_gas()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleInput_brake gas(::cm_msgs::msg::VehicleInput::_gas_type arg)
  {
    msg_.gas = std::move(arg);
    return Init_VehicleInput_brake(msg_);
  }

private:
  ::cm_msgs::msg::VehicleInput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::msg::VehicleInput>()
{
  return cm_msgs::msg::builder::Init_VehicleInput_gas();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__BUILDER_HPP_
