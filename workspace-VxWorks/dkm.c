#include "tasks.h"
#include "taskset.h"

TASK_ID taskDirectionGen;
TASK_ID taskMovementGen;
TASK_ID taskPhotographGen;
TASK_ID taskGeologicalSampleGen;
TASK_ID taskAtmosphericGen;
TASK_ID taskAltitudeGen;
TASK_ID taskTemperatureGen;
TASK_ID taskSandStormGen;

void start(void)
{
    // Semaphore
    mov = newMutex();
    updateCeiling(mov, P3);
    updateCeiling(mov, P4);
    updateCeiling(mov, P5);

    // Mailbox
    cmd = mq_open("cmd", O_RDWR);
    prs = mq_open("prs", O_RDWR);

    // Spawn
    taskDirectionGen = taskSpawn("generatorTaskDirection", 0, 0, 4000, (FUNCPTR)generatorDirectionTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskMovementGen = taskSpawn("generatorTaskMovement", 0, 0, 4000, (FUNCPTR)generatorMovementTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskPhotographGen = taskSpawn("generatorTaskPhotograph", 0, 0, 4000, (FUNCPTR)generatorPhotographTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskGeologicalSampleGen = taskSpawn("generatorTaskGeological", 0, 0, 4000, (FUNCPTR)generatorGeologicalSampleTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskAtmosphericGen = taskSpawn("generatorTaskAtmospheric", 0, 0, 4000, (FUNCPTR)generatorAtmosphericPressureTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskAltitudeGen = taskSpawn("generatorTaskAltitude", 0, 0, 4000, (FUNCPTR)generatorAltitudeRecordTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskTemperatureGen = taskSpawn("generatorTaskTemperature", 0, 0, 4000, (FUNCPTR)generatorTemperatureRecordTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    taskSandStormGen = taskSpawn("generatorTaskSandStorm", 0, 0, 4000, (FUNCPTR)generatorSandStormDetectionTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void stop(void)
{
    taskDelete(taskDirectionGen);
    taskDelete(taskMovementGen);
    taskDelete(taskPhotographGen);
    taskDelete(taskGeologicalSampleGen);
    taskDelete(taskAtmosphericGen);
    taskDelete(taskAltitudeGen);
    taskDelete(taskTemperatureGen);
    taskDelete(taskSandStormGen);

    if (taskSatellite != NULL)
    {
        taskDelete(taskSatellite);
    }

    if (taskDirection != NULL)
    {
        taskDelete(taskDirection);
    }

    if (taskMovement != NULL)
    {
        taskDelete(taskMovement);
    }

    if (taskPhotograph != NULL)
    {
        taskDelete(taskPhotograph);
    }

    if (taskGeologicalSample != NULL)
    {
        taskDelete(taskGeologicalSample);
    }

    if (taskAtmosphericPressure != NULL)
    {
        taskDelete(taskAtmosphericPressure);
    }

    if (taskAltitudeRecord != NULL)
    {
        taskDelete(taskAltitudeRecord);
    }

    if (taskTemperatureRecord != NULL)
    {
        taskDelete(taskTemperatureRecord);
    }

    if (taskSandStormDetection != NULL)
    {
        taskDelete(taskSandStormDetection);
    }

    mq_close(cmd);
    mq_close(prs);

    free(mov);
}