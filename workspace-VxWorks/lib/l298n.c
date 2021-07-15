#include "l298n.h"

void init_shield(){
    pinMode(ENA, OUT);
    pinMode(ENB, OUT);
    pinMode(IN1, OUT);
    pinMode(IN2, OUT);
    pinMode(IN3, OUT);
    pinMode(IN4, OUT);

    // right
    gpioWrite(ENA, HIGH);

    // left
    gpioWrite(ENB, HIGH);
}

/* SIDES */
void right_forward(){
    gpioWrite(IN1, HIGH);
    gpioWrite(IN2, LOW);
}

void right_backward(){
    gpioWrite(IN1, LOW);
    gpioWrite(IN2, HIGH);
}

void right_braking(){
    gpioWrite(IN1, LOW);
    gpioWrite(IN2, LOW);
}

void left_forward(){
    gpioWrite(IN3, LOW);
    gpioWrite(IN4, HIGH);
}

void left_backward(){
    gpioWrite(IN3, HIGH);
    gpioWrite(IN4, LOW);
}

void left_braking(){
    gpioWrite(IN3, LOW);
    gpioWrite(IN4, LOW);
}

/* CAR */
void forward(){
    right_forward();
    left_forward();
}

void backward(){
    right_backward();
    left_backward();
}

void left_rotate(){
    right_forward();
    left_backward();
}

void right_rotate(){
    right_backward();
    left_forward();
}

void stop_vehicle(){
    right_braking();
    left_braking();
}
