#include "busySleep.h"

#include <vxWorks.h>
#include <usrLib.h>
#include <stdio.h>

void busySleepByNumCycles(long long numCycles);
void linearRegression(const double *x, const double *y, int size);

void getBusySleepParams(long long numCycles, int numSteps, int numExp) {
    double *numCyclesArray = malloc(sizeof(double) * numSteps);
    double *timeArray = malloc(sizeof(double) * numSteps);

    for (int step = 0; step < numSteps; step++, numCycles = (long long) (numCycles * 1.2)) {
    	UINT32 time1, time2, time3;

    	time1 = sysTimestamp();
		for (int i = 0; i < numExp; i++);
		time2 = sysTimestamp();
		for (int i = 0; i < numExp; i++) {
			busySleepByNumCycles(numCycles);
		}
		time3 = sysTimestamp();
        
        long measured = (long)(time3 - 2 * time2 + time1) * 1000 / sysTimestampFreq() / numExp;
        printf("%d/%d Num cycles: %10lld time %.3f s\n", step + 1, numSteps, numCycles, measured / 1000.);
        
        numCyclesArray[step] = (double) numCycles;
        timeArray[step] = (double) measured;
    }

    linearRegression(numCyclesArray, timeArray, numSteps);
    free(numCyclesArray);
    free(timeArray);
}

void busySleep(int ms) {
	// Paste here your busy sleep params
	double a = 3.167546e-05;
	double b = -5.655099e-01;
	
    long long numCycles = (long long) ((ms - b) / a);
    int count = 0;
    for (long long i = 0; i < numCycles; i++) {
        count++;
        count--;
        count++;
    }
}

void testBusySleep(int ms, int numExp) {
	sysClkRateSet(100);
    printf("Test busy sleep for %d ms\n", ms);
    
    UINT32 time1, time2, time3 = 0;

    time1 = sysTimestamp();
	for (int i = 0; i < numExp; i++);
	time2 = sysTimestamp();
	for (int i = 0; i < numExp; i++) {
		busySleep(ms);
	}
	time3 = sysTimestamp();
    
    long measured = (long)(time3 - 2 * time2 + time1) * 1000 / sysTimestampFreq() / numExp;
	printf("Measured time: %.3f ms (error: %f us)\n", measured / 1., (measured/1. - ms/1.)*1000);
}


void busySleepErrorHistogram(int ms, int numExp) {
	printf("Busy sleep histogram for %d ms\n", ms);

	int histogramSize = 100;
	long *histogram = malloc(sizeof(long) * histogramSize);
	for (int i = 0; i < histogramSize; i++) {
		histogram[i] = 0;
	}

	UINT32 time1, time2;
	for (int i = 0; i < numExp; i++) {
		time1 = sysTimestamp();
		busySleep(ms);
		time2 = sysTimestamp();
		long error = (long) (time2 - time1) * 1000 / sysTimestampFreq() - ms;
		if (error >= -histogramSize / 2 && error <= histogramSize / 2)
			histogram[error + histogramSize / 2]++;
		printf("\rProgress %.2f%%", (float) i / numExp * 100);
	}
	
	printf("\n");

	for (int i = 0; i < histogramSize; i++) {
		printf("\rErrors %d: %d   \n", i - histogramSize / 2, histogram[i]);		
	}
}

// Private functions
void busySleepByNumCycles(long long numCycles) {
    long long count = 0;
    for (long long i = 0; i < numCycles; i++) {
        count++;
        count--;
        count++;
    }
}

void linearRegression(const double *x, const double *y, int size) {
    double xSum = 0, x2Sum = 0, ySum = 0, xySum = 0;

    for (int i = 0; i < size; i++) {
    	xSum += x[i];
    	x2Sum += x[i] * x[i];
    	ySum += y[i];
    	xySum += x[i] * y[i];
    }
    double den = size * x2Sum - xSum * xSum;
    double a = (size * xySum - xSum * ySum) / den;
    double b = (ySum * x2Sum - xSum * xySum) / den;
    printf("\nEquation of best fit is: y = %e + %ex\n", b, a);
    printf("Params are:\ndouble a = %e;\ndouble b = %e;\n", a, b);
}
