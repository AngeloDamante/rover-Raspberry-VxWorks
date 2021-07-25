/*
 * tasks.h
 * Header to define generator tasks.
 * 
 * Periodic Tasks:
 *  - taskDirectionGen;
 *  - taskMovementGen;
 *  - taskPhotographGen;
 *  - taskGeologicalSampleGen;
 *  - taskAtmosphericGen;
 *  - taskAltitudeGen;
 *  - taskTemperatureGen;
 *  - taskSandStormGen;
 * 
 * Sporadic Task:
 *  - spawnSatelliteTask();
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

/* includes */
#include "taskset.h"
#include "utility/utils.h"
#include "utility/log.h"


void spawnSatelliteTask()
{
    /// Boost
    taskPrioritySet(taskIdSelf(), 0);

    /// Affinity to CPU single core
    cpuset_t affinity;
    CPUSET_ZERO(affinity);
    CPUSET_SET(affinity, 1);
    taskCpuAffinitySet(taskIdSelf(), affinity);

    /// Spawn
    taskSatellite = taskSpawn("Satellite", (int)P1, 0, 4000, (FUNCPTR)jobSatellite, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
    /// Record log
    logEvent(logs, "t_1r");
}

void generatorDirectionTask()
{
    while (true)
    {
        taskDelay(msToTick(T2));
        taskDirection = taskSpawn("Direction", (int)P2, 0, 4000, (FUNCPTR)jobDirection, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        logEvent(logs, "t_2r");
    }
}

void generatorMovementTask()
{
    /// Offset
    taskDelay(msToTick(PHASE)); 
    logEvent(logs, "t_3o");
    while (true)
    {
        taskDelay(msToTick(T3));
        taskMovement = taskSpawn("Movement", (int)P3, 0, 4000, (FUNCPTR)jobMovement, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        logEvent(logs, "t_3r");
    }
}

void generatorPhotographTask()
{
    while (true)
    {
        taskDelay(msToTick(T4));
        taskPhotograph = taskSpawn("Photograph", (int)P4, 0, 4000, (FUNCPTR)jobPhotograph, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        logEvent(logs, "t_4r");
    }
}

void generatorGeologicalSampleTask()
{
    while (true)
    {
        taskDelay(msToTick(T5));
        taskGeologicalSample = taskSpawn("Geological", (int)P5, 0, 4000, (FUNCPTR)jobGeologicalSample, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        logEvent(logs, "t_5r");
    }
}

void generatorAtmosphericPressureTask()
{
    while (true)
    {
        taskDelay(msToTick(T6));
        taskAtmosphericPressure = taskSpawn("Atmospheric", (int)P6, 0, 4000, (FUNCPTR)jobAtmosphericPressure, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        logEvent(logs, "t_6r");
    }
}

void generatorAltitudeRecordTask()
{
    while (true)
    {
        char *prs = (char *)malloc(sizeof(long));
        msgQReceive(cmd, prs, 8, WAIT_FOREVER);
        taskAltitudeRecord = taskSpawn("Altitude", (int)P7, 0, 4000, (FUNCPTR)jobAltitudeRecord, (long)*prs, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

void generatorTemperatureRecordTask()
{
    while (true)
    {
        taskDelay(msToTick(T8));
        taskTemperatureRecord = taskSpawn("Temperature", (int)P8, 0, 4000, (FUNCPTR)jobTemperatureRecord, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        logEvent(logs, "t_8r");
    }
}

void generatorSandStormDetectionTask()
{
    while (true)
    {
        taskDelay(msToTick(T9));
        taskSandStormDetection = taskSpawn("SandStormDetection", (int)P9, 0, 4000, (FUNCPTR)jobSandStormDetection, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        logEvent(logs, "t_9r");
    }
}
