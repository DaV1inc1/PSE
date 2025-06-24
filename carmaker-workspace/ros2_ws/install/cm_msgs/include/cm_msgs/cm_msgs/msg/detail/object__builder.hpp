// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cm_msgs:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_
#define CM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cm_msgs/msg/detail/object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cm_msgs
{

namespace msg
{

namespace builder
{

class Init_Object_object
{
public:
  Init_Object_object()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cm_msgs::msg::Object object(::cm_msgs::msg::Object::_object_type arg)
  {
    msg_.object = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cm_msgs::msg::Object msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cm_msgs::msg::Object>()
{
  return cm_msgs::msg::builder::Init_Object_object();
}

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_
