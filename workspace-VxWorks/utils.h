#ifndef UTILS_H
#define UTILS_H
#include "vxWorks.h"
#include <time.h>
#include <errno.h>    

extern int msleep(long ms);

extern long executionTime(long BCET, long WCET);

extern int msToTick(long ms);

#endif /* UTILS_H*/
