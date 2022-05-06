// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rttf_car_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__struct.h"
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _WheelsCmdStamped__ros_msg_type = rttf_car_interfaces__msg__WheelsCmdStamped;

static bool _WheelsCmdStamped__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _WheelsCmdStamped__ros_msg_type * ros_message = static_cast<const _WheelsCmdStamped__ros_msg_type *>(untyped_ros_message);
  // Field name: velocity
  {
    cdr << ros_message->velocity;
  }

  // Field name: rotation
  {
    cdr << ros_message->rotation;
  }

  return true;
}

static bool _WheelsCmdStamped__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _WheelsCmdStamped__ros_msg_type * ros_message = static_cast<_WheelsCmdStamped__ros_msg_type *>(untyped_ros_message);
  // Field name: velocity
  {
    cdr >> ros_message->velocity;
  }

  // Field name: rotation
  {
    cdr >> ros_message->rotation;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rttf_car_interfaces
size_t get_serialized_size_rttf_car_interfaces__msg__WheelsCmdStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WheelsCmdStamped__ros_msg_type * ros_message = static_cast<const _WheelsCmdStamped__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name velocity
  {
    size_t item_size = sizeof(ros_message->velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rotation
  {
    size_t item_size = sizeof(ros_message->rotation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _WheelsCmdStamped__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rttf_car_interfaces__msg__WheelsCmdStamped(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rttf_car_interfaces
size_t max_serialized_size_rttf_car_interfaces__msg__WheelsCmdStamped(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rotation
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _WheelsCmdStamped__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rttf_car_interfaces__msg__WheelsCmdStamped(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_WheelsCmdStamped = {
  "rttf_car_interfaces::msg",
  "WheelsCmdStamped",
  _WheelsCmdStamped__cdr_serialize,
  _WheelsCmdStamped__cdr_deserialize,
  _WheelsCmdStamped__get_serialized_size,
  _WheelsCmdStamped__max_serialized_size
};

static rosidl_message_type_support_t _WheelsCmdStamped__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_WheelsCmdStamped,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rttf_car_interfaces, msg, WheelsCmdStamped)() {
  return &_WheelsCmdStamped__type_support;
}

#if defined(__cplusplus)
}
#endif
