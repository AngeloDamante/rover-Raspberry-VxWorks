#include "lib/gpioLib.h"
#include <unistd.h>

#define ENA 12
#define ENB 13
#define IN1 5
#define IN2 6
#define IN3 19
#define IN4 26

void setup(){
    pinMode(ENA, OUT);
    pinMode(ENB, OUT);
    pinMode(IN1, OUT);
    pinMode(IN2, OUT);
    pinMode(IN3, OUT);
    pinMode(IN4, OUT);
}

void test_motor(){
    setup();

    /*RIGHT*/
    gpioWrite(ENA, HIGH);

    // forward
    gpioWrite(IN1, HIGH);
    gpioWrite(IN2, LOW);
    sleep(5);

    // stop 
    gpioWrite(IN1, LOW);
    sleep(5);

    // backward
    gpioWrite(IN2, HIGH);
    sleep(5);

    // stop
    gpioWrite(IN1, HIGH);
    sleep(5);
    
}

void start(void){
    test_motor();
}