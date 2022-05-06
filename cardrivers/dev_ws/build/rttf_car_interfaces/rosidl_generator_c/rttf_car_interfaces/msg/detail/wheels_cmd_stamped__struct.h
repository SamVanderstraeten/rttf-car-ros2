// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#ifndef RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__STRUCT_H_
#define RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/WheelsCmdStamped in the package rttf_car_interfaces.
typedef struct rttf_car_interfaces__msg__WheelsCmdStamped
{
  float velocity;
  float rotation;
} rttf_car_interfaces__msg__WheelsCmdStamped;

// Struct for a sequence of rttf_car_interfaces__msg__WheelsCmdStamped.
typedef struct rttf_car_interfaces__msg__WheelsCmdStamped__Sequence
{
  rttf_car_interfaces__msg__WheelsCmdStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rttf_car_interfaces__msg__WheelsCmdStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__STRUCT_H_
