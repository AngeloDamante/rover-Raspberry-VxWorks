#include "pin.h"
#include "gpioLib.h"

void init_shield();

/* SIDES */
void right_forward();
void right_backward();
void right_braking();

void left_forward();
void left_backward();
void left_braking();

/* VEHICLE */
void forward();
void backward();

void left_rotate();
void right_rotate();

void stop_vehicle();
