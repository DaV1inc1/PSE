// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cm_msgs:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef CM_MSGS__MSG__DETAIL__OBJECT__STRUCT_H_
#define CM_MSGS__MSG__DETAIL__OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'object'
#include "std_msgs/msg/detail/bool__struct.h"

/// Struct defined in msg/Object in the package cm_msgs.
typedef struct cm_msgs__msg__Object
{
  std_msgs__msg__Bool object;
} cm_msgs__msg__Object;

// Struct for a sequence of cm_msgs__msg__Object.
typedef struct cm_msgs__msg__Object__Sequence
{
  cm_msgs__msg__Object * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cm_msgs__msg__Object__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CM_MSGS__MSG__DETAIL__OBJECT__STRUCT_H_
