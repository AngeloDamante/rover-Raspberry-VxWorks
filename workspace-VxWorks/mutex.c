#include "mutex.h"

/* newMutex(): creates and returns a mutex */
struct mutex* newMutex() {
	struct mutex *mux = malloc(sizeof(struct mutex));
	mux->ceiling = -1;
	mux->sem = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE);
	return mux;
}

/* updateCeiling(): updates the ceiling of a mutex if the priority of the new task is greater */
void updateCeiling(struct mutex* mux, int c) {
	if (mux->ceiling < c) {
		mux->ceiling = c;
	}
}
