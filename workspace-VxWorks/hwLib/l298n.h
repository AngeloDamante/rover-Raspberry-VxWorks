/*
 * l298n.h
 * Interface to control l298n module with VxWorks.
 * 
 * Right motor truth table:
 *  ENA         IN1               IN2         Description  
 *  LOW   Not Applicable    Not Applicable    Motor is off
 *  HIGH        LOW               LOW         Motor is stopped (brakes)
 *  HIGH        HIGH              LOW         Motor is on and turning forwards
 *  HIGH        LOW               HIGH        Motor is on and turning backwards
 *  HIGH        HIGH              HIGH        Motor is stopped (brakes)
 * 
 * Left motor truth table:
 *  ENB         IN3             IN4         Description  
 *  LOW   Not Applicable   Not Applicable   Motor is off
 *  HIGH        LOW             LOW         Motor is stopped (brakes)
 *  HIGH        LOW             HIGH        Motor is on and turning forwards
 *  HIGH        HIGH            LOW         Motor is on and turning backwards
 *  HIGH        HIGH            HIGH        Motor is stopped (brakes)   
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

#ifndef L298N_H
#define L298N_H

/* includes */
#include "pin.h"
#include "gpioLib.h"

/* 
 * init_motor_shield - func
 * Set all pin mode of l298n shield.
*/
void init_motor_shield();

/* 
 * right_forward - func
 * Both right motors go forward.
*/
void right_forward();

/*
 * right_backward - func
 * Both right motors go backward.
*/
void right_backward();

/*
 * right_braking - func
 * Both right motors stop.
*/
void right_braking();

/*
 * left_forward - func
 * Both left motors go forward.
*/
void left_forward();

/*
 * left_backward - func
 * Both left motors go backward.
*/
void left_backward();

/*
 * left_braking - func
 * Both left motors stop.
*/
void left_braking();

/* VEHICLE CONTROLS */
void forward_vehicle();
void backward_vehicle();

void left_rotate_vehicle();
void right_rotate_vehicle();

void stop_vehicle();
void free_bus_vehicle();

#endif /* L298N_H */