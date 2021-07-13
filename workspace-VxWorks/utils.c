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
long executionTime(long BCET, long WCET) {
	return rand() % (WCET - BCET + 1) + BCET;
}

/* msToTick(): returns the number of ticks in a requested number of milliseconds */
int msToTick(long ms) {
	return (int) sysClkRateGet() * ((float) ms / 1000.0);
}
