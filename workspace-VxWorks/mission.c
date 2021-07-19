#include "mission.h"

void load_mission_file()
{
    ack = 0;
    // UINT32 start = sysTimestampLock();

    // FILE *filePointer, *fptr;
    // int bufferLength = 255;
    // char buffer[bufferLength];

    // counting
    fptr = fopen("mission.txt", "r");
    len_mission = 0;
    while (fgets(buffer, 255, fptr))
    {
        len_mission++;
    }
    fclose(fptr);

    // load mission
    filePointer = fopen("mission.txt", "r");
    int i = 0;
    mission = (int *)malloc(sizeof(int) * len_mission);
    while (fgets(buffer, 255, filePointer))
    {
        // printf("%s\n", buffer);
        if (strcmp(buffer, "FORWARD\n") == 0)
        {
            mission[i] = FORWARD;
        }

        if (strcmp(buffer, "BACKWARD\n") == 0)
        {
            mission[i] = BACKWARD;
        }

        if (strcmp(buffer, "RIGHT_ROTATE\n") == 0)
        {
            mission[i] = RIGHT_ROTATE;
        }

        if (strcmp(buffer, "LEFT_ROTATE\n") == 0)
        {
            mission[i] = LEFT_ROTATE;
        }

        if (strcmp(buffer, "STOP") == 0)
        {
            mission[i] = STOP;
        }

        i++;
    }

    fclose(filePointer);

    // UINT32 end = sysTimestampLock();

	// long ms = intervalToMs(start, end);
	// printf("time: %ld", ms);
}