/*
 * entrypoints.h
 * Header to define all chunks.
 * 
 * The chunks functions return an int for testing purposes. 
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

#ifndef ENTRYPOINTS_H
#define ENTRYPOINTS_H

/* includes */
#include "hwLib/gpioLib.h"
#include "hwLib/pin.h"
#include "hwLib/l298n.h"
#include "utility/utils.h"
#include "utility/busySleep.h"
#include "tasksetSpec.h"
#include "mission.h"
#include <unistd.h>

/// Task 1
int transmitData();

/// Task 2
int loadPositions();
int computeDest();

/// Task 3
int receiveCmd();
int move();

/// Task 4
int takePhoto();

/// Task 5
int drill();
int collect();

/// Task 6
int recordPress();

/// Task 7
int recordAltitude();

/// Task 8
int recordTemp();

/// Task 9
int recordStorm();

#endif /* ENTRYPOINTS_H */
