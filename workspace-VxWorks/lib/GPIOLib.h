#ifndef GPIOLIB_H
#define GPIOLIB_H
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

typedef struct gpioSetStruct
{
    UINT32 gpioNum;
    UINT32 val;
} gpioSetType;

extern int gpioSetVal(gpioSetType *gSet);
extern int gpioGetVal(gpioSetType *gSet);
extern int gpioSetDir(gpioSetType *gSet);
extern int gpioGetDir(gpioSetType *gSet);

int gpioWrite(UINT32 gpioNum, UINT32 value);
int gpioRead(UINT32 gpioNum);
int pinMode(UINT32 gpioNum, UINT32 value);

#endif /* GPIOLIB_H */
