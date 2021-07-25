/*
 * MOTORS_time_test.c
 * Downloadable Kernel Module to test timings for 4 DC motors and l298n shield.
 * 
 * - default_mission tests timing for default mission.
 * - test_motors tests timing for complete mission.
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

/* includes */
#include "vxWorks.h"
#include <stdio.h>
#include <usrLib.h>
#include <unistd.h>
#include "utility/utils.h"
#include "hwLib/l298n.h"
#include "utility/busySleep.h"
#include "mission.h"

#define NUM_TESTS 1000000
#define PIN_LED 23

void default_mission(void)
{
	UINT32 start = sysTimestampLock();

	/* Setting up pin */
	init_motor_shield();

	for (int i = 0; i < NUM_TESTS; i++)
	{
		// go forward
		forward_vehicle();

		// go right
		right_rotate_vehicle();

		// go left
		left_rotate_vehicle();

		// go backward
		backward_vehicle();
	}

	stop_vehicle();

	UINT32 end = sysTimestampLock();

	long ms = intervalToMs(start, end);
	printf("time: %ld", ms);
}


void test_motors(void)
{
	load_mission_file();
	init_motor_shield();

	UINT32 start = sysTimestampLock();

	for (int i = 0; i < NUM_TESTS; i++)
	{
		if (ack < len_mission)
		{

			switch (mission[ack])
			{
			case FORWARD:
				forward_vehicle();
				break;

			case BACKWARD:
				backward_vehicle();
				break;

			case LEFT_ROTATE:
				left_rotate_vehicle();

				stop_vehicle();

				break;

			case RIGHT_ROTATE:
				right_rotate_vehicle();

				stop_vehicle();

				break;

			case STOP:
				stop_vehicle();

				break;

			default:
				break;
			}
			ack = (ack + 1) % len_mission;
		}
		stop_vehicle();
	}
	
	UINT32 end = sysTimestampLock();

	long ms = intervalToMs(start, end);
	printf("time: %ld", ms);
}