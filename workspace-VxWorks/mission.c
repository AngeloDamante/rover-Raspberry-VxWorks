/* includes */
#include "mission.h"

void load_mission_file()
{
    /// First ack
    ack = 0;

    /// Lines counting
    fptr = fopen("mission.txt", "r");
    len_mission = 0;
    while (fgets(buffer, 255, fptr))
    {
        len_mission++;
    }
    fclose(fptr);

    /// Store in mission structure
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
}