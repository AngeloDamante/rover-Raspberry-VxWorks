/*
 * mission.h
 * Header to define mission directives and load file function.
 * 
 * Global mission structures:
 *  - mission(int*): structure to store the directives read from the mission.txt file.
 *  - len_mission(int): global variable to store number of lines of mission.txt file.
 *  - ack(int): global index to sign actual mission directive. 
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
*/

#ifndef MISSION_H
#define MISSION_H

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vxWorks.h"
#include <usrLib.h>
#include "utility/utils.h"

/// @type move_directive: collect of mission directives
enum move_directive
{
    FORWARD,
    BACKWARD,
    RIGHT_ROTATE,
    LEFT_ROTATE,
    STOP
};

/// Global mission structures
int *mission;
int len_mission;
int ack;

/// Global file structures
FILE *filePointer, *fptr;
char buffer[255];

/// Function to load file defined by user
void load_mission_file();

#endif /* MISSION_H */