#include "pin.h"
#include "GPIOLib.h"

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

void rotate_left();
void rotate_right();

void stop();
