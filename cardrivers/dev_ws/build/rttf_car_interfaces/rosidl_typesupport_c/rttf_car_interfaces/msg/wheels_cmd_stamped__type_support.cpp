// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rttf_car_interfaces/msg/rosidl_typesupport_c__visibility_control.h"
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rttf_car_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _WheelsCmdStamped_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _WheelsCmdStamped_type_support_ids_t;

static const _WheelsCmdStamped_type_support_ids_t _WheelsCmdStamped_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _WheelsCmdStamped_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _WheelsCmdStamped_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _WheelsCmdStamped_type_support_symbol_names_t _WheelsCmdStamped_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rttf_car_interfaces, msg, WheelsCmdStamped)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rttf_car_interfaces, msg, WheelsCmdStamped)),
  }
};

typedef struct _WheelsCmdStamped_type_support_data_t
{
  void * data[2];
} _WheelsCmdStamped_type_support_data_t;

static _WheelsCmdStamped_type_support_data_t _WheelsCmdStamped_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _WheelsCmdStamped_message_typesupport_map = {
  2,
  "rttf_car_interfaces",
  &_WheelsCmdStamped_message_typesupport_ids.typesupport_identifier[0],
  &_WheelsCmdStamped_message_typesupport_symbol_names.symbol_name[0],
  &_WheelsCmdStamped_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t WheelsCmdStamped_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_WheelsCmdStamped_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace rttf_car_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_rttf_car_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rttf_car_interfaces, msg, WheelsCmdStamped)() {
  return &::rttf_car_interfaces::msg::rosidl_typesupport_c::WheelsCmdStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
