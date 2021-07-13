#include <vxWorks.h>
#include <taskLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysLib.h>
#include <subsys/gpio/vxbGpioLib.h>
#include "GPIOLib.h"

#ifdef GPIO_SYSCALL
#include <private/syscallLibP.h>
#include <syscall.h>
#include <syscallLib.h>
#include <private/syscallLibP.h>

#define GPIO_GROUP            7
#define GPIO_GROUP_NAME       "gpioGroup"
#endif /* GPIO_SYSCALL */

/*******************************************************************************
 * 
 * gpioSetVal - Set the value of the specified pin
 * 
 * Set the value of the GPIO pin
 * 
 * RETURNS: void
 * 
 * \NOMANUAL
 */
int gpioSetVal(gpioSetType* gSet)
{
    return (vxbGpioSetValue(gSet->gpioNum, gSet->val));
}

/*******************************************************************************
 * 
 * gpioGetVal - Return the value of the specified pin
 * 
 * Get the value of the GPIO pin
 * 
 * RETURNS: void
 * 
 * \NOMANUAL
 */
int gpioGetVal(gpioSetType* gSet)
{
    gSet->val = vxbGpioGetValue(gSet->gpioNum);
    return OK;
}

/*******************************************************************************
 * 
 * gpioSetDir - Set the direction of the specified pin
 * 
 * Set the direction, input or output, of the GPIO pin
 * 
 * RETURNS: OK
 * 
 * \NOMANUAL
 */
int gpioSetDir(gpioSetType* gSet)
{
    return (vxbGpioSetDir(gSet->gpioNum, gSet->val));
}

/*******************************************************************************
 * 
 * gpioGetDir - Return the direction of the specified pin
 * 
 * Get the direction, input or output, of the GPIO pin
 * 
 * RETURNS: direction of the pin 
 * 
 * \NOMANUAL
 */
int gpioGetDir(gpioSetType * gSet)
{
    gSet->val = vxbGpioGetDir(gSet->gpioNum);
    return OK;
}

#ifdef GPIO_SYSCALL
_WRS_DATA_ALIGN_BYTES(16) SYSCALL_RTN_TBL_ENTRY tempTbl[] =
    {
    SYSCALL_DESC_ENTRY (gpioSetVal, "GpioSet", 2),
    SYSCALL_DESC_ENTRY (gpioGetVal, "GpioGet", 2),
    SYSCALL_DESC_ENTRY (gpioSetDir, "GpioSetDir", 2),
    SYSCALL_DESC_ENTRY (gpioGetDir, "GpioGetDir", 2),
    };

STATUS gpioGroup(void)
    {
    if (syscallGroupRegister (GPIO_GROUP, GPIO_GROUP_NAME,
                              4, tempTbl, TRUE) == ERROR)
        {
         printf( "GPIO syscall registration FAILED");
         return ERROR;
    }
    
    printf( "GPIO syscall registration SUCCEEDED");
    return OK;
    }

//TODO add latency for GPIO calls

void registerGpioSyscalls(void) 
    {
    gpioGroup();
    }


STATUS syscallRegistrationHook
    (
    int                      groupNum,     /* group number */
    char *                   groupName,    /* group name */
    int                      numRoutines,  /* num routines in group */
    SYSCALL_RTN_TBL_ENTRY ** ppRoutineTbl  /* addr of routine table */
    );

STATUS syscallRegisterHookAdd
    (
    SYSCALL_REGISTER_HOOK startMyDkm, /* routine to call upon group registration */
    BOOL                  addToHead   /* add routine to head of list */
    );

#endif /* GPIO_SYSCALL */
