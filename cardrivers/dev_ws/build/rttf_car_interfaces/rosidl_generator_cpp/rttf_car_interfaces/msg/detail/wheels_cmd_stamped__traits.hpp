// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#ifndef RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__TRAITS_HPP_
#define RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__TRAITS_HPP_

#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rttf_car_interfaces::msg::WheelsCmdStamped>()
{
  return "rttf_car_interfaces::msg::WheelsCmdStamped";
}

template<>
inline const char * name<rttf_car_interfaces::msg::WheelsCmdStamped>()
{
  return "rttf_car_interfaces/msg/WheelsCmdStamped";
}

template<>
struct has_fixed_size<rttf_car_interfaces::msg::WheelsCmdStamped>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rttf_car_interfaces::msg::WheelsCmdStamped>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rttf_car_interfaces::msg::WheelsCmdStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__TRAITS_HPP_
