// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice

#ifndef RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__FUNCTIONS_H_
#define RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rttf_car_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__struct.h"

/// Initialize msg/WheelsCmdStamped message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rttf_car_interfaces__msg__WheelsCmdStamped
 * )) before or use
 * rttf_car_interfaces__msg__WheelsCmdStamped__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
bool
rttf_car_interfaces__msg__WheelsCmdStamped__init(rttf_car_interfaces__msg__WheelsCmdStamped * msg);

/// Finalize msg/WheelsCmdStamped message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
void
rttf_car_interfaces__msg__WheelsCmdStamped__fini(rttf_car_interfaces__msg__WheelsCmdStamped * msg);

/// Create msg/WheelsCmdStamped message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rttf_car_interfaces__msg__WheelsCmdStamped__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
rttf_car_interfaces__msg__WheelsCmdStamped *
rttf_car_interfaces__msg__WheelsCmdStamped__create();

/// Destroy msg/WheelsCmdStamped message.
/**
 * It calls
 * rttf_car_interfaces__msg__WheelsCmdStamped__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
void
rttf_car_interfaces__msg__WheelsCmdStamped__destroy(rttf_car_interfaces__msg__WheelsCmdStamped * msg);


/// Initialize array of msg/WheelsCmdStamped messages.
/**
 * It allocates the memory for the number of elements and calls
 * rttf_car_interfaces__msg__WheelsCmdStamped__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
bool
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__init(rttf_car_interfaces__msg__WheelsCmdStamped__Sequence * array, size_t size);

/// Finalize array of msg/WheelsCmdStamped messages.
/**
 * It calls
 * rttf_car_interfaces__msg__WheelsCmdStamped__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
void
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__fini(rttf_car_interfaces__msg__WheelsCmdStamped__Sequence * array);

/// Create array of msg/WheelsCmdStamped messages.
/**
 * It allocates the memory for the array and calls
 * rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence *
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__create(size_t size);

/// Destroy array of msg/WheelsCmdStamped messages.
/**
 * It calls
 * rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rttf_car_interfaces
void
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__destroy(rttf_car_interfaces__msg__WheelsCmdStamped__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // RTTF_CAR_INTERFACES__MSG__DETAIL__WHEELS_CMD_STAMPED__FUNCTIONS_H_
