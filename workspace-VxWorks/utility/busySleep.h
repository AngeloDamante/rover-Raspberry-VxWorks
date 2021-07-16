#ifndef BUSYSLEEP_H_
#define BUSYSLEEP_H_

void busySleep(int ms);

void getBusySleepParams(long long numCycles, int numSteps, int numExp);

void testBusySleep(int ms, int numExp);

#endif /* BUSYSLEEP_H_ */
