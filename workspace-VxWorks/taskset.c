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
    msgQSend(prs, msg, 25, WAIT_FOREVER, MSG_PRI_NORMAL);

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobMovement()
{
    // C31
    char *msg = (char *)malloc(25 * sizeof(char));
    msgQReceive(prs, msg, 25, WAIT_FOREVER);
    receiveCmd();

    // C32 -> Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    pinMode(MUTEX, OUT);
    gpioWrite(MUTEX, HIGH);
    move();
    semGive(mov->sem);
    gpioWrite(MUTEX, LOW);

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobPhotograph()
{
    // C41 -> Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    pinMode(MUTEX, OUT);
    gpioWrite(MUTEX, HIGH);
    takePhoto();
    semGive(mov->sem);
    gpioWrite(MUTEX, LOW);

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
    pinMode(MUTEX, OUT);
    gpioWrite(MUTEX, HIGH);
    drill();   // C51
    collect(); // C52
    semGive(mov->sem);
    gpioWrite(MUTEX, LOW);

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
    printf("msgSend! \n");
    msgQSend(cmd, msg, 25, WAIT_FOREVER, MSG_PRI_NORMAL);

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobAltitudeRecord(char* msg)
{
    // C71
    recordAltitude();

    // Receive
    printf("msgReceived! \n");

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
