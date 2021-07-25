/*
 * mutex.h
 * Header to define mutex structure and functions.
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
 * @Special_Tanks_to: Andrea Puccia, Lorenzo Nuti, Lorenzo Mandelli
*/

#ifndef MUTEX_H_
#define MUTEX_H_

/* includes */
#include "vxWorks.h"
#include "usrLib.h"

/* Mutex semaphore with ceiling*/
struct mutex {
	SEM_ID sem;
	int ceiling;
};

/* Functions to handle mutex*/
extern struct mutex* newMutex();
extern void updateCeiling(struct mutex* m, int c);

#endif /* MUTEX_H_ */
