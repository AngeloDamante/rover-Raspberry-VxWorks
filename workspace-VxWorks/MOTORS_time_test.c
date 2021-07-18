/* includes */

#include "vxWorks.h"
#include <stdio.h>
#include <usrLib.h>
#include "utility/utils.h"
#include "hwLib/l298n.h"

#define NUM_TESTS 1000000
#define PIN_LED 23

void start(void)
{
	UINT32 start = sysTimestampLock();

	/* Setting up pin */
	init_motor_shield();

	for (int i = 0; i < NUM_TESTS; i++)
	{
		// go forward
		forward();

		// go right
		right_rotate();

		// go left
		left_forward();

		// go backward
		backward();
	}

	stop_vehicle();

	UINT32 end = sysTimestampLock();

	long ms = intervalToMs(start, end);
	printf("time: %ld", ms);
}
