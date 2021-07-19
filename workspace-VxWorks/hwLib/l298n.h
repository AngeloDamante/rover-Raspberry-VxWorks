#ifndef L298N_H
#define L298N_H

#include "pin.h"
#include "gpioLib.h"

void init_motor_shield();

/* SIDES */
void right_forward();
void right_backward();
void right_braking();

void left_forward();
void left_backward();
void left_braking();

/* VEHICLE */
void forward_vehicle();
void backward_vehicle();

void left_rotate_vehicle();
void right_rotate_vehicle();

void stop_vehicle();
void free_bus_vehicle();

#endif /* L298N_H */