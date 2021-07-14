/* includes */

#include "vxWorks.h"
#include <stdio.h>
#include <usrLib.h>
#include "utils.h"
#include "GPIOLib.h"

#define NUM_TESTS	1000000

void start(void) {
	UINT32 start = sysTimestampLock();
	
	struct gpioSetStruct gpioPin;
	gpioPin.gpioNum = 23;
	
	/* Setting up pin */
	gpioPin.val = PINMODE_OUT;
	gpioSetDir(&gpioPin);

	for (int i = 0; i < NUM_TESTS; i++) {
		/* turning on pin */
		gpioPin.val = OUTMODE_HIGH;
		gpioSetVal(&gpioPin);
		
		/* turning off pin */
		gpioPin.val = OUTMODE_LOW;
		gpioSetVal(&gpioPin);
	}

	UINT32 end = sysTimestampLock();
	
	long ms = intervalToMs(start, end);
	printf("time: %ld", ms);
}
