// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:msg/VehicleState.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_
#define CM_MSGS__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/msg/detail/vehicle_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleState_velocity
{
public:
  Init_VehicleState_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cm_msgs::msg::VehicleState velocity(::cm_msgs::msg::VehicleState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::msg::VehicleState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::msg::VehicleState>()
{
  return cm_msgs::msg::builder::Init_VehicleState_velocity();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_
