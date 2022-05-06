// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rttf_car_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void WheelsCmdStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rttf_car_interfaces::msg::WheelsCmdStamped(_init);
}

void WheelsCmdStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rttf_car_interfaces::msg::WheelsCmdStamped *>(message_memory);
  typed_message->~WheelsCmdStamped();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WheelsCmdStamped_message_member_array[2] = {
  {
    "velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rttf_car_interfaces::msg::WheelsCmdStamped, velocity),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rotation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rttf_car_interfaces::msg::WheelsCmdStamped, rotation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WheelsCmdStamped_message_members = {
  "rttf_car_interfaces::msg",  // message namespace
  "WheelsCmdStamped",  // message name
  2,  // number of fields
  sizeof(rttf_car_interfaces::msg::WheelsCmdStamped),
  WheelsCmdStamped_message_member_array,  // message members
  WheelsCmdStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  WheelsCmdStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WheelsCmdStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WheelsCmdStamped_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rttf_car_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rttf_car_interfaces::msg::WheelsCmdStamped>()
{
  return &::rttf_car_interfaces::msg::rosidl_typesupport_introspection_cpp::WheelsCmdStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rttf_car_interfaces, msg, WheelsCmdStamped)() {
  return &::rttf_car_interfaces::msg::rosidl_typesupport_introspection_cpp::WheelsCmdStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
