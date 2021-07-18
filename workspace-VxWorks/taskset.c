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
    mq_send(cmd, msg, sizeof(char) * 25, NULL); // FIXME MAGIC NUMBER

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobMovement()
{
    // C31
    char *msg = (char *)malloc(25 * sizeof(char));
    mq_receive(cmd, msg, sizeof(char) * 25, NULL); // FIXME MAGIC NUMBER
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
    mq_send(prs, msg, sizeof(char) * 25, NULL); // FIXME MAGIC NUMBER

    // End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobAltitudeRecord()
{
    // Notify
    mq_notify(prs, &sigv);

    // Affinity
    cpuset_t affinity;
    CPUSET_ZERO(affinity);
    CPUSET_SET(affinity, 1);
    taskCpuAffinitySet(taskIdSelf(), affinity);

    // Priority
    taskPrioritySet(taskIdSelf(), P7);
    
    // C71
    char *msg = (char *)malloc(25 * sizeof(char));
    mq_receive(prs, msg, sizeof(char) * 25, NULL); // FIXME MAGIC NUMBER
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
