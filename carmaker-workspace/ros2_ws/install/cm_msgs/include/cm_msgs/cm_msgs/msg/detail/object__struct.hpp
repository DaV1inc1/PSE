// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__OBJECT__STRUCT_HPP_
#define CM_MSGS__MSG__DETAIL__OBJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'object'
#include "std_msgs/msg/detail/bool__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cm_msgs__msg__Object __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__msg__Object __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Object_
{
  using Type = Object_<ContainerAllocator>;

  explicit Object_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object(_init)
  {
    (void)_init;
  }

  explicit Object_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _object_type =
    std_msgs::msg::Bool_<ContainerAllocator>;
  _object_type object;

  // setters for named parameter idiom
  Type & set__object(
    const std_msgs::msg::Bool_<ContainerAllocator> & _arg)
  {
    this->object = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::msg::Object_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::msg::Object_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::msg::Object_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::msg::Object_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::Object_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::Object_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::Object_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::Object_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::msg::Object_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::msg::Object_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__msg__Object
    std::shared_ptr<cm_msgs::msg::Object_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__msg__Object
    std::shared_ptr<cm_msgs::msg::Object_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Object_ & other) const
  {
    if (this->object != other.object) {
      return false;
    }
    return true;
  }
  bool operator!=(const Object_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Object_

// alias to use template instance with default allocator
using Object =
  cm_msgs::msg::Object_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__OBJECT__STRUCT_HPP_
