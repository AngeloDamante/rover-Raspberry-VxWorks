#ifndef TASKSET_H
#define TASKSET_H

#include "vxWorks.h"
#include "semLib.h"
#include "hwLib/gpioLib.h"
#include "hwLib/pin.h"
#include "utility/utils.h"
#include "utility/busySleep.h"
#include "utility/mutex.h"

#include <stdio.h>
#include <mqueue.h>
#include <signal.h>
#include "entrypoints.h"

TASK_ID taskSatellite;
TASK_ID taskDirection;
TASK_ID taskMovement;
TASK_ID taskPhotograph;
TASK_ID taskGeologicalSample;
TASK_ID taskAtmosphericPressure;
TASK_ID taskAltitudeRecord;
TASK_ID taskTemperatureRecord;
TASK_ID taskSandStormDetection;

int jobSatellite();
int jobDirection();
int jobMovement();
int jobPhotograph();
int jobGeologicalSample();
int jobAtmosphericPressure();
int jobAltitudeRecord();
int jobTemperatureRecord();
int jobSandStormDetection();

struct sigevent sigv;
struct mutex *mov;
mqd_t cmd, prs;

#endif /* TASKSET_H */