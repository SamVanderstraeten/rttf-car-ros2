// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__rosidl_typesupport_introspection_c.h"
#include "rttf_car_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__functions.h"
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rttf_car_interfaces__msg__WheelsCmdStamped__init(message_memory);
}

void WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_fini_function(void * message_memory)
{
  rttf_car_interfaces__msg__WheelsCmdStamped__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_member_array[2] = {
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rttf_car_interfaces__msg__WheelsCmdStamped, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rttf_car_interfaces__msg__WheelsCmdStamped, rotation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_members = {
  "rttf_car_interfaces__msg",  // message namespace
  "WheelsCmdStamped",  // message name
  2,  // number of fields
  sizeof(rttf_car_interfaces__msg__WheelsCmdStamped),
  WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_member_array,  // message members
  WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_type_support_handle = {
  0,
  &WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rttf_car_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rttf_car_interfaces, msg, WheelsCmdStamped)() {
  if (!WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_type_support_handle.typesupport_identifier) {
    WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &WheelsCmdStamped__rosidl_typesupport_introspection_c__WheelsCmdStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
