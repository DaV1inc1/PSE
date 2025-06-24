// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cm_msgs:msg/VehicleInput.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__STRUCT_HPP_
#define CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cm_msgs__msg__VehicleInput __attribute__((deprecated))
#else
# define DEPRECATED__cm_msgs__msg__VehicleInput __declspec(deprecated)
#endif

namespace cm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleInput_
{
  using Type = VehicleInput_<ContainerAllocator>;

  explicit VehicleInput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gas = 0.0;
      this->brake = 0.0;
    }
  }

  explicit VehicleInput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gas = 0.0;
      this->brake = 0.0;
    }
  }

  // field types and members
  using _gas_type =
    double;
  _gas_type gas;
  using _brake_type =
    double;
  _brake_type brake;

  // setters for named parameter idiom
  Type & set__gas(
    const double & _arg)
  {
    this->gas = _arg;
    return *this;
  }
  Type & set__brake(
    const double & _arg)
  {
    this->brake = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cm_msgs::msg::VehicleInput_<ContainerAllocator> *;
  using ConstRawPtr =
    const cm_msgs::msg::VehicleInput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::VehicleInput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cm_msgs::msg::VehicleInput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cm_msgs__msg__VehicleInput
    std::shared_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cm_msgs__msg__VehicleInput
    std::shared_ptr<cm_msgs::msg::VehicleInput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleInput_ & other) const
  {
    if (this->gas != other.gas) {
      return false;
    }
    if (this->brake != other.brake) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleInput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleInput_

// alias to use template instance with default allocator
using VehicleInput =
  cm_msgs::msg::VehicleInput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cm_msgs

#endif  // CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__STRUCT_HPP_
