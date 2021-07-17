#include "utils.h"
#include <usrLib.h>

/* msleep(): sleeps for the requested number of milliseconds. */
int msleep(long ms) {
    struct timespec ts;
    int res;

    if (ms < 0) {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

/* executionTime():  returns a random execution time between a min and a max*/
int executionTime(int BCET, int WCET) {
	return rand() % (WCET - BCET + 1) + BCET;
}

/* msToTick(): returns the number of ticks in a requested number of milliseconds */
unsigned int msToTick(int ms) {
	return sysClkRateGet() * (ms / 1000);
}

/* intervalToMs(): returns the number of milliseconds from two timestamps */
long intervalToMs(UINT32 start, UINT32 end){
	return (long) (end-start) * 1000 / sysTimestampFreq();
}
