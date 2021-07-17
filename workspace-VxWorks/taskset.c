#include "taskset.h"

int jobSatellite()
{
    // C11
    transmitData();

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobDirection()
{
    // C21
    loadPositions();

    // C22
    computeDest();
    char *msg = "Direction_send_msg";
    mq_send(cmd, msg, sizeof(char) * 50, NULL); // FIXME MAGIC NUMBER

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobMovement()
{
    // C31
    char *msg;
    mq_receive(cmd, msg, sizeof(char) * 50, NULL); // FIXME MAGIC NUMBER
    receiveCmd();

    // C32 -> Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    move();
    semGive(mov->sem);

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobPhotograph()
{
    // C41 -> Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    takePhoto();
    semGive(mov->sem);

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobGeologicalSample()
{
    // boost
    taskPrioritySet(taskIdSelf(), mov->ceiling);

    // Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    drill();   // C51
    collect(); // C52
    semGive(mov->sem);

    // boost
    taskPrioritySet(taskIdSelf(), P5);

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobAtmosphericPressure()
{
    // C61
    recordPress();
    char *msg = "AtmPresSensor_send_msg";
    mq_send(prs, msg, sizeof(char) * 50, NULL); // FIXME MAGIC NUMBER

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobAltitudeRecord()
{
    // C71
    char *msg;
    mq_receive(prs, msg, sizeof(char) * 50, NULL); // FIXME MAGIC NUMBER
    recordAltitude();

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobTemperatureRecord()
{
    // C81
    recordTemp();

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobSandStormDetection()
{
    // C91
    recordStorm();

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}
