#include "gpioLib.h"

int gpioWrite(UINT32 gpioNum, UINT32 value)
{
    return (vxbGpioSetValue(gpioNum, value));
}

int gpioRead(UINT32 gpioNum)
{
    return vxbGpioGetValue(gpioNum);
}

int pinMode(UINT32 gpioNum, UINT32 value)
{
    return vxbGpioSetDir(gpioNum, value);
}

