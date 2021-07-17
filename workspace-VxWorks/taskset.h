#ifndef TASKSET_H
#define TASKSET_H

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

#endif /* TASKSET_H */