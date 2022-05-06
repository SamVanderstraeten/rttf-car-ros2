// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rttf_car_interfaces:msg/WheelsCmdStamped.idl
// generated code does not contain a copyright notice
#include "rttf_car_interfaces/msg/detail/wheels_cmd_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
rttf_car_interfaces__msg__WheelsCmdStamped__init(rttf_car_interfaces__msg__WheelsCmdStamped * msg)
{
  if (!msg) {
    return false;
  }
  // velocity
  // rotation
  return true;
}

void
rttf_car_interfaces__msg__WheelsCmdStamped__fini(rttf_car_interfaces__msg__WheelsCmdStamped * msg)
{
  if (!msg) {
    return;
  }
  // velocity
  // rotation
}

rttf_car_interfaces__msg__WheelsCmdStamped *
rttf_car_interfaces__msg__WheelsCmdStamped__create()
{
  rttf_car_interfaces__msg__WheelsCmdStamped * msg = (rttf_car_interfaces__msg__WheelsCmdStamped *)malloc(sizeof(rttf_car_interfaces__msg__WheelsCmdStamped));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rttf_car_interfaces__msg__WheelsCmdStamped));
  bool success = rttf_car_interfaces__msg__WheelsCmdStamped__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rttf_car_interfaces__msg__WheelsCmdStamped__destroy(rttf_car_interfaces__msg__WheelsCmdStamped * msg)
{
  if (msg) {
    rttf_car_interfaces__msg__WheelsCmdStamped__fini(msg);
  }
  free(msg);
}


bool
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__init(rttf_car_interfaces__msg__WheelsCmdStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rttf_car_interfaces__msg__WheelsCmdStamped * data = NULL;
  if (size) {
    data = (rttf_car_interfaces__msg__WheelsCmdStamped *)calloc(size, sizeof(rttf_car_interfaces__msg__WheelsCmdStamped));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rttf_car_interfaces__msg__WheelsCmdStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rttf_car_interfaces__msg__WheelsCmdStamped__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__fini(rttf_car_interfaces__msg__WheelsCmdStamped__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rttf_car_interfaces__msg__WheelsCmdStamped__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rttf_car_interfaces__msg__WheelsCmdStamped__Sequence *
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__create(size_t size)
{
  rttf_car_interfaces__msg__WheelsCmdStamped__Sequence * array = (rttf_car_interfaces__msg__WheelsCmdStamped__Sequence *)malloc(sizeof(rttf_car_interfaces__msg__WheelsCmdStamped__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__destroy(rttf_car_interfaces__msg__WheelsCmdStamped__Sequence * array)
{
  if (array) {
    rttf_car_interfaces__msg__WheelsCmdStamped__Sequence__fini(array);
  }
  free(array);
}
