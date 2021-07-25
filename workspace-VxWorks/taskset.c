/* includes */
#include "taskset.h"

int jobSatellite()
{
    /// C11
    transmitData();
    logEvent(logs, "t_11e");

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobDirection()
{
    /// C21
    loadPositions();
    logEvent(logs, "t_21e");

    /// C22
    computeDest();
    logEvent(logs, "t_22e");
    
    /// Send
    char *msg = "Direction_send_msg";
    msgQSend(prs, msg, 25, WAIT_FOREVER, MSG_PRI_NORMAL);

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobMovement()
{
    /// Receive
    char *msg = (char *)malloc(25 * sizeof(char));
    msgQReceive(prs, msg, 25, WAIT_FOREVER);
    logEvent(logs, "t_31g");
    
    /// C31
    receiveCmd();
    logEvent(logs, "t_31e");

    /// C32 -> Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    logEvent(logs, "t_32w");
    
    pinMode(MUTEX, OUT);
    gpioWrite(MUTEX, HIGH);
    
    move();
    logEvent(logs, "t_32e");
    
    semGive(mov->sem);
    
    gpioWrite(MUTEX, LOW);

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobPhotograph()
{
    /// C41 -> Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    logEvent(logs, "t_41w");
    
    pinMode(MUTEX, OUT);
    gpioWrite(MUTEX, HIGH);
    
    takePhoto();
    logEvent(logs, "t_41e");
    
    semGive(mov->sem);
    
    gpioWrite(MUTEX, LOW);

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobGeologicalSample()
{
    /// boost
    taskPrioritySet(taskIdSelf(), mov->ceiling);
    logEvent(logs, "t_51b");

    /// Critical Section
    semTake(mov->sem, WAIT_FOREVER);
    logEvent(logs, "t_51w");
    
    pinMode(MUTEX, OUT);
    gpioWrite(MUTEX, HIGH);
    
    drill();   // C51
    logEvent(logs, "t_51e");
    
    collect(); // C52
    logEvent(logs, "t_52e");
    
    semGive(mov->sem);
    
    gpioWrite(MUTEX, LOW);

    /// deboost
    taskPrioritySet(taskIdSelf(), P5);

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobAtmosphericPressure()
{
    /// C61
    recordPress();
    logEvent(logs, "t_61e");
    
    /// Send
    long prs = 8000; // pressure on Mars
    msgQSend(cmd, (char*)&prs, 8, WAIT_FOREVER, MSG_PRI_NORMAL);

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobAltitudeRecord(long prs)
{
    /// C71
    recordAltitude();
    logEvent(logs, "t_71e");

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobTemperatureRecord()
{
    /// C81
    recordTemp();
    logEvent(logs, "t_81e");

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}

int jobSandStormDetection()
{
    /// C91
    recordStorm();
    logEvent(logs, "t_91e");

    /// End Job
    taskDelete(taskIdSelf());
    return 0;
}
