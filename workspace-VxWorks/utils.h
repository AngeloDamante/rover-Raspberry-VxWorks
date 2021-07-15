#ifndef UTILS_H
#define UTILS_H
#include "vxWorks.h"
#include <time.h>
#include <errno.h>    

extern int msleep(long ms);

extern long executionTime(long BCET, long WCET);

extern long msToTick(long ms);

extern long intervalToMs(UINT32 start, UINT32 end);

#endif /* UTILS_H*/
