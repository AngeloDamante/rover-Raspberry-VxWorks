/*
 * gpioLib.h
 * Interface to control GPIO bus on Raspberry Pi 3B+ with VxWorks.
 * 
 * Inspired by Arduino digital IO functions. 
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

#ifndef GPIOLIB_H
#define GPIOLIB_H

/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "sysLib.h"
#include <subsys/gpio/vxbGpioLib.h>

#define OUT 1
#define IN 0

#define HIGH 1
#define LOW 0

/*
 * pinMode - func
 * Configures the specified pin to behave either as an input or an output.
 * 
 * @params pinGpioNum (UINT32): the GPIO bus pin number to set the mode of (BCM).
 * @params mode (UINT32): OUT, IN.
 * 
 * @returns int value to testing.
*/
int pinMode(UINT32 pinGpioNum, UINT32 mode);

/*
 * gpioWrite - func
 * Write a HIGH or a LOW value to a digital pin.
 * 
 * If the pin has been configured as an OUT with pinMode(), its voltage 
 *  will be set to the corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH, 
 *  0V (ground) for LOW.
 * 
 * If the pin is configured as an IN, gpioWrite() will enable (HIGH) or disable (LOW)
 *  the internal pullup on the input pin.
 * 
 * @params pinGpioNum (UINT32): the GPIO bus pin number.
 * @params value (UINT32): HIGH, LOW.
 * 
 * @returns int value to testing.
*/
int gpioWrite(UINT32 pinGpioNum, UINT32 value);

/*
 * gpioRead - func
 * Reads the value from a specified digital pin, either HIGH or LOW.
 * 
 * @params pinGpioNum (UINT32): the GPIO pin number you want to read.
 * 
 * @returns int value to testing.
*/
int gpioRead(UINT32 pinGpioNum);

/*
 * gpioFree - func
 * Free pin of GPIO bus to erase cumulated voltage.
 * 
 * @params pinGpioNum (UINT32): the GPIO pin number you want to free.
 * 
 * @returns int value to testing.
*/
int gpioFree(UINT32 pinGpioNum);

#endif /* GPIOLIB_H */
