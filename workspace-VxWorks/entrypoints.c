#include "entrypoints.h"

int transmitData()
{
    // Turn ON Sensor
    pinMode(ANTENNA, OUT);
    gpioWrite(ANTENNA, HIGH);

    // Computation
    busySleep(executionTime(C11_BCET, C11_WCET));

    // Turn OFF Sensor
    gpioWrite(ANTENNA, LOW);

    return 0;
}

int loadPositions()
{
    // Computation
    busySleep(executionTime(C21_BCET, C21_WCET));

    return 0;
}

int computeDest()
{
    // Computation
    busySleep(executionTime(C22_BCET, C22_WCET));

    return 0;
}

int receiveCmd()
{
    // Computation
    busySleep(executionTime(C31_BCET, C31_WCET));

    return 0;
}

int move()
{
    // Turn ON Sensor
    pinMode(MOTORS, OUT);
    gpioWrite(MOTORS, HIGH);

    // Computation Mission
    right_rotate();
    busySleep(400);
    forward();
    busySleep(450);

    // Turn OFF Sensor
    stop_vehicle();
    gpioWrite(MOTORS, LOW);

    return 0;
}

int takePhoto()
{
    // Turn ON Sensor
    pinMode(CAMERA, OUT);
    gpioWrite(CAMERA, HIGH);

    // Computation
    busySleep(executionTime(C41_BCET, C41_WCET));

    // Turn OFF Sensor
    gpioWrite(CAMERA, LOW);

    return 0;
}

int drill()
{
    // Turn ON Sensor
    pinMode(DRILL, OUT);
    gpioWrite(DRILL, HIGH);

    // Computation
    busySleep(executionTime(C51_BCET, C51_WCET));

    // Turn OFF Sensor
    gpioWrite(DRILL, LOW);

    return 0;
}

int collect()
{
    // Turn ON Sensor
    pinMode(ROB_ARM, OUT);
    gpioWrite(ROB_ARM, HIGH);

    // Computation
    busySleep(executionTime(C52_BCET, C52_WCET));

    // Turn OFF Sensor
    gpioWrite(ROB_ARM, LOW);

    return 0;
}

int recordPress()
{
    // Turn ON Sensor
    pinMode(PRESS_SENS, OUT);
    gpioWrite(PRESS_SENS, HIGH);

    // Computation
    busySleep(executionTime(C61_BCET, C61_WCET));

    // Turn OFF Sensor
    gpioWrite(PRESS_SENS, LOW);

    return 0;
}

int recordAltitude()
{
    // Computation
    busySleep(executionTime(C71_BCET, C71_WCET));

    return 0;
}

int recordTemp()
{
    // Turn ON Sensor
    pinMode(TEMP_SENS, OUT);
    gpioWrite(TEMP_SENS, HIGH);

    // Computation
    busySleep(executionTime(C81_BCET, C81_WCET));

    // Turn OFF Sensor
    gpioWrite(TEMP_SENS, LOW);

    return 0;
}

int recordStorm()
{
    // Turn ON Sensor
    pinMode(STORM_SENS, OUT);
    gpioWrite(STORM_SENS, HIGH);

    // Computation
    busySleep(executionTime(C91_BCET, C91_WCET));

    // Turn OFF Sensor
    gpioWrite(STORM_SENS, LOW);

    return 0;
}