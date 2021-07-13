#ifndef __INCgpioLibH
#define __INCgpioLibH
#include "vxWorks.h"
#include "taskLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "sysLib.h"
#include <subsys/gpio/vxbGpioLib.h>

#define PINMODE_OUT		1
#define PINMODE_IN		0
#define OUTMODE_HIGH	1
#define OUTMODE_LOW		0
#define INMODE_HIGH		1
#define INMODE_LOW		0

typedef struct gpioSetStruct
{
    UINT32 gpioNum;
    UINT32 val;
} gpioSetType;

extern int gpioSetVal(gpioSetType * gSet);
extern int gpioGetVal(gpioSetType * gSet);
extern int gpioSetDir(gpioSetType * gSet);
extern int gpioGetDir(gpioSetType * gSet);

#endif /* __INCgpioLibH */
