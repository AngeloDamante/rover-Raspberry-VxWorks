/*
 * busySleep.h
 * Header to define busySleep functions.
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
 * @Special_Tanks_to: Andrea Puccia, Lorenzo Nuti, Lorenzo Mandelli
*/

#ifndef BUSYSLEEP_H_
#define BUSYSLEEP_H_

/* To simulate computation time by (y = ax + b) relation */
void busySleep(int ms);

/* To find out a and b params */
void getBusySleepParams(long long numCycles, int numSteps, int numExp);

/* To measure error */
void testBusySleep(int ms, int numExp);

#endif /* BUSYSLEEP_H_ */
