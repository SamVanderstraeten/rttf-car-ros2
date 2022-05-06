// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#ifndef RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__BUILDER_HPP_
#define RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__BUILDER_HPP_

#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rttf_car_interfaces
{

namespace msg
{

namespace builder
{

class Init_WheelsCmdStamped_rotation
{
public:
  explicit Init_WheelsCmdStamped_rotation(::rttf_car_interfaces::msg::WheelsCmdStamped & msg)
  : msg_(msg)
  {}
  ::rttf_car_interfaces::msg::WheelsCmdStamped rotation(::rttf_car_interfaces::msg::WheelsCmdStamped::_rotation_type arg)
  {
    msg_.rotation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rttf_car_interfaces::msg::WheelsCmdStamped msg_;
};

class Init_WheelsCmdStamped_velocity
{
public:
  Init_WheelsCmdStamped_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WheelsCmdStamped_rotation velocity(::rttf_car_interfaces::msg::WheelsCmdStamped::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_WheelsCmdStamped_rotation(msg_);
  }

private:
  ::rttf_car_interfaces::msg::WheelsCmdStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rttf_car_interfaces::msg::WheelsCmdStamped>()
{
  return rttf_car_interfaces::msg::builder::Init_WheelsCmdStamped_velocity();
}

}  // namespace rttf_car_interfaces

#endif  // RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__BUILDER_HPP_
