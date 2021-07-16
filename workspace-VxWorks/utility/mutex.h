#ifndef MUTEX_H_
#define MUTEX_H_

#include "vxWorks.h"
#include "usrLib.h"

/* Mutex semaphore with ceiling*/
struct mutex {
	SEM_ID sem;
	int ceiling;
};

extern struct mutex* newMutex();

extern void updateCeiling(struct mutex* m, int c);

#endif /* MUTEX_H_ */
