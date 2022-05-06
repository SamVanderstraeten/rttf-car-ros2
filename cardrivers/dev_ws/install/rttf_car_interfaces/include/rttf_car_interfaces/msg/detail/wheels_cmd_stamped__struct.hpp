// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#ifndef RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__STRUCT_HPP_
#define RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rttf_car_interfaces__msg__WheelsCmdStamped __attribute__((deprecated))
#else
# define DEPRECATED__rttf_car_interfaces__msg__WheelsCmdStamped __declspec(deprecated)
#endif

namespace rttf_car_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WheelsCmdStamped_
{
  using Type = WheelsCmdStamped_<ContainerAllocator>;

  explicit WheelsCmdStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0f;
      this->rotation = 0.0f;
    }
  }

  explicit WheelsCmdStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0f;
      this->rotation = 0.0f;
    }
  }

  // field types and members
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _rotation_type =
    float;
  _rotation_type rotation;

  // setters for named parameter idiom
  Type & set__velocity(
    const float & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__rotation(
    const float & _arg)
  {
    this->rotation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rttf_car_interfaces__msg__WheelsCmdStamped
    std::shared_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rttf_car_interfaces__msg__WheelsCmdStamped
    std::shared_ptr<rttf_car_interfaces::msg::WheelsCmdStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WheelsCmdStamped_ & other) const
  {
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->rotation != other.rotation) {
      return false;
    }
    return true;
  }
  bool operator!=(const WheelsCmdStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WheelsCmdStamped_

// alias to use template instance with default allocator
using WheelsCmdStamped =
  rttf_car_interfaces::msg::WheelsCmdStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rttf_car_interfaces

#endif  // RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__STRUCT_HPP_
