// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cm_msgs:msg/VehicleInput.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cm_msgs/msg/detail/vehicle_input__rosidl_typesupport_introspection_c.h"
#include "cm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cm_msgs/msg/detail/vehicle_input__functions.h"
#include "cm_msgs/msg/detail/vehicle_input__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cm_msgs__msg__VehicleInput__init(message_memory);
}

void cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_fini_function(void * message_memory)
{
  cm_msgs__msg__VehicleInput__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_member_array[2] = {
  {
    "gas",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__VehicleInput, gas),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "brake",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cm_msgs__msg__VehicleInput, brake),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_members = {
  "cm_msgs__msg",  // message namespace
  "VehicleInput",  // message name
  2,  // number of fields
  sizeof(cm_msgs__msg__VehicleInput),
  cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_member_array,  // message members
  cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_init_function,  // function to initialize message memory (memory has to be allocated)
  cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_type_support_handle = {
  0,
  &cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cm_msgs, msg, VehicleInput)() {
  if (!cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_type_support_handle.typesupport_identifier) {
    cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cm_msgs__msg__VehicleInput__rosidl_typesupport_introspection_c__VehicleInput_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
