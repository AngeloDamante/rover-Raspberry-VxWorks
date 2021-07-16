#include "log.h"

#include <usrLib.h>
#include <stdio.h>
#include <string.h>

#define MAX_MSGS   	100000
#define MSG_LENGTH  sizeof(struct event)

struct event {
    char transition[5];
    struct timespec time;
};


MSG_Q_ID initLogger(){
	MSG_Q_ID logQueue = msgQCreate(MAX_MSGS, MSG_LENGTH, MSG_Q_FIFO);
	struct timespec time;
	time.tv_sec = 0;
	time.tv_nsec = 0;
	clock_settime(CLOCK_REALTIME, &time);
	return logQueue;
}

void logEvent(MSG_Q_ID logQueue, char * transition){
    struct event log;
    clock_gettime(CLOCK_REALTIME, &log.time);
    memcpy(&log.transition, transition, 5*sizeof(char));
    msgQSend(logQueue, (char *) &log, MSG_LENGTH, WAIT_FOREVER, MSG_PRI_NORMAL);
}

void saveLog(MSG_Q_ID logQueue, char * fileName) {
    struct event log;
    time_t lastTime = 0;

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (msgQReceive(logQueue, (char *) &log, MSG_LENGTH, NO_WAIT) != ERROR) {
        time_t time = log.time.tv_sec * 1000 + log.time.tv_nsec / 1000000l;
        fprintf(file, "%s\n%llu\n", log.transition, time - lastTime);
        lastTime = time;
    }
    fclose(file);
    printf("Log saved: %.3f s\n", lastTime / 1000.);
}
