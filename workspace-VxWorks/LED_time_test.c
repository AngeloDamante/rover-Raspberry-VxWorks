/* includes */

#include "vxWorks.h"
#include <stdio.h>
#include <usrLib.h>
#include "include/utils.h"
#include "hwLib/gpioLib.h"

#define NUM_TESTS 1000000
#define PIN_LED 23

void start(void)
{
	UINT32 start = sysTimestampLock();

	/* Setting up pin */
	pinMode(PIN_LED, OUT);

	for (int i = 0; i < NUM_TESTS; i++)
	{
		/* turning on pin */
		gpioWrite(PIN_LED, HIGH);

		/* turning off pin */
		gpioWrite(PIN_LED, LOW);
	}

	UINT32 end = sysTimestampLock();

	long ms = intervalToMs(start, end);
	printf("time: %ld", ms);
}
