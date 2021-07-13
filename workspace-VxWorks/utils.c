#include "utils.h"

/* msleep(): Sleep for the requested number of milliseconds. */
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
