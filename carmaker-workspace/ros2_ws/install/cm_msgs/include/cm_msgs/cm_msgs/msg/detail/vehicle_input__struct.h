// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:msg/VehicleInput.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__STRUCT_H_
#define CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/VehicleInput in the package cm_msgs.
typedef struct cm_msgs__msg__VehicleInput
{
  double gas;
  double brake;
} cm_msgs__msg__VehicleInput;

// Struct for a sequence of cm_msgs__msg__VehicleInput.
typedef struct cm_msgs__msg__VehicleInput__Sequence
{
  cm_msgs__msg__VehicleInput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__msg__VehicleInput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__MSG__DETAIL__VEHICLE_INPUT__STRUCT_H_
