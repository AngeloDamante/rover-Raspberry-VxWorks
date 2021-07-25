/*
 * LED_time_test.c
 * Downloadable Kernel Module to test timings for leds ("sensors").
 * 
 * - test_led tests timing for ON-OFF led.
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

/* includes */
#include "vxWorks.h"
#include <stdio.h>
#include <usrLib.h>
#include "utility/utils.h"
#include "hwLib/gpioLib.h"

#define NUM_TESTS 1000000
#define PIN_LED 23

void test_led(void)
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
