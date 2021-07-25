/*
 * taskset.h
 * Header to define task jobs.
 * 
 * The jobs functions return an int for testing purposes. 
 * Handle of semaphores and mailboxes.
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

#ifndef TASKSET_H
#define TASKSET_H

/* includes */
#include "vxWorks.h"
#include "semLib.h"
#include "msgQLib.h"
#include "hwLib/gpioLib.h"
#include "hwLib/pin.h"
#include "utility/utils.h"
#include "utility/busySleep.h"
#include "utility/mutex.h"
#include "utility/log.h"

#include <stdio.h>
#include "entrypoints.h"

/// Tasks names
TASK_ID taskSatellite;
TASK_ID taskDirection;
TASK_ID taskMovement;
TASK_ID taskPhotograph;
TASK_ID taskGeologicalSample;
TASK_ID taskAtmosphericPressure;
TASK_ID taskAltitudeRecord;
TASK_ID taskTemperatureRecord;
TASK_ID taskSandStormDetection;

/// Job Task 1
int jobSatellite();

/// Job Task 2
int jobDirection();

/// Job Task 3
int jobMovement();

/// Job Task 4
int jobPhotograph();

/// Job Task 5
int jobGeologicalSample();

/// Job Task 6
int jobAtmosphericPressure();

/// Job Task 7
int jobAltitudeRecord(long prs);

/// Job Task 8
int jobTemperatureRecord();

/// Job Task 9
int jobSandStormDetection();

/// Semaphore
struct mutex *mov;

/// Mailboxes
MSG_Q_ID cmd, prs;
MSG_Q_ID logs;

#endif /* TASKSET_H */
