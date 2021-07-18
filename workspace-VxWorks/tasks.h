#include "taskset.h"
#include "utility/utils.h"
#include <signal.h>

void spawnSatelliteTask()
{
    taskPrioritySet(taskIdSelf(), 0); // boost
    cpuset_t affinity;
    CPUSET_ZERO(affinity);
    CPUSET_SET(affinity, 1);
    taskCpuAffinitySet(taskIdSelf(), affinity);
    taskSatellite = taskSpawn("Satellite", (int)P1, 0, 4000, (FUNCPTR)jobSatellite, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void generatorDirectionTask()
{
    while (true)
    {
        taskDelay(msToTick(T2));
        taskDirection = taskSpawn("Direction", (int)P2, 0, 4000, (FUNCPTR)jobDirection, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorMovementTask()
{
    taskDelay(msToTick(PHASE));
    while (true)
    {
        taskDelay(msToTick(T3));
        taskMovement = taskSpawn("Movement", (int)P3, 0, 4000, (FUNCPTR)jobMovement, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorPhotographTask()
{
    while (true)
    {
        taskDelay(msToTick(T4));
        taskPhotograph = taskSpawn("Photograph", (int)P4, 0, 4000, (FUNCPTR)jobPhotograph, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorGeologicalSampleTask()
{
    while (true)
    {
        taskDelay(msToTick(T5));
        taskGeologicalSample = taskSpawn("Geological", (int)P5, 0, 4000, (FUNCPTR)jobGeologicalSample, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorAtmosphericPressureTask()
{
    while (true)
    {
        taskDelay(msToTick(T6));
        taskAtmosphericPressure = taskSpawn("Atmospheric", (int)P6, 0, 4000, (FUNCPTR)jobAtmosphericPressure, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorAltitudeRecordTask()
{
    while (true)
    {
    	char *msg = (char *)malloc(25 * sizeof(char));
    	msgQReceive(cmd, msg, 25, WAIT_FOREVER);
		taskAltitudeRecord = taskSpawn("Altitude", (int)P7, 0, 4000, (FUNCPTR)jobAltitudeRecord, (long)msg, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorTemperatureRecordTask()
{
    while (true)
    {
        taskDelay(msToTick(T8));
        taskTemperatureRecord = taskSpawn("Temperature", (int)P8, 0, 4000, (FUNCPTR)jobTemperatureRecord, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorSandStormDetectionTask()
{
    while (true)
    {
        taskDelay(msToTick(T9));
        taskSandStormDetection = taskSpawn("SandStormDetection", (int)P9, 0, 4000, (FUNCPTR)jobSandStormDetection, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}
