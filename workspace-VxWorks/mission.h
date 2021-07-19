#ifndef MISSION_H
#define MISSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vxWorks.h"
#include <usrLib.h>
#include "utility/utils.h"

enum options
{
    FORWARD,
    BACKWARD,
    RIGHT_ROTATE,
    LEFT_ROTATE,
    STOP
};

int *mission;
int len_mission;
int ack;

FILE *filePointer, *fptr;
char buffer[255];

void load_mission_file();

// void load_mission()
// {
//     FILE *filePointer, *fptr;
//     int bufferLength = 255;
//     char buffer[bufferLength];

//     // counting
//     fptr = fopen("mission.txt", "r");
//     int len = 0;
//     while (fgets(buffer, bufferLength, fptr))
//     {
//         len++;
//     }
//     fclose(fptr);
//     printf("%d\n", len);

//     // load mission
//     filePointer = fopen("foo.txt", "r");
//     int i = 0;
//     mission = (int*)malloc(sizeof(int)*len);
//     while (fgets(buffer, bufferLength, filePointer))
//     {
//         // printf("%s\n", buffer);
//         if (strcmp(buffer, "FORWARD\n") == 0)
//         {
//             mission[i] = FORWARD;
//         }
//         if (strcmp(buffer, "BACKWARD\n") == 0)
//         {
//             mission[i] = BACKWARD;
//         }
//         if (strcmp(buffer, "RIGHT_ROTATE\n") == 0)
//         {
//             mission[i] = RIGHT_ROTATE;
//         }
//         if (strcmp(buffer, "LEFT_ROTATE\n") == 0)
//         {
//             mission[i] = LEFT_ROTATE;
//         }
//         if (strcmp(buffer, "STOP") == 0)
//         {
//             mission[i] = STOP;
//         }

//         i++;
//     }

//     fclose(filePointer);
// }

#endif /* MISSION_H */