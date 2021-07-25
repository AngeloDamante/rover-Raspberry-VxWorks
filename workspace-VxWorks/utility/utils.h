/*
 * utils.h
 * Header to define utility functions.
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
 * @Special_Tanks_to: Andrea Puccia, Lorenzo Nuti, Lorenzo Mandelli
*/

#ifndef UTILS_H
#define UTILS_H

/* includes */
#include "vxWorks.h"
#include <time.h>
#include <errno.h>

#define true 1
#define false 0

extern int msleep(long ms);
extern int executionTime(int BCET, int WCET);
extern unsigned int msToTick(int ms);
extern long intervalToMs(UINT32 start, UINT32 end);

#endif /* UTILS_H*/
