#ifndef TASKSET_SPEC_H
#define TASKSET_SPEC_H

/* Task 1 - Satellite */
#define P1 1
#define C11_BCET 200
#define C11_WCET 250

/* Task 2 - Direction */
#define T2 5000
#define P2 2
#define C21_BCET 100
#define C21_WCET 125
#define C22_BCET 50
#define C22_WCET 100

/* Task 3 - Movement */
#define T3 5000
#define P3 2
#define PHASE 2500
#define C31_BCET 50
#define C31_WCET 75
#define C32_BCET 800
#define C32_WCET 900

/* Task 4 - Photograph */
#define T4 10000
#define P4 2
#define C41_BCET 200
#define C41_WCET 250

/* Task 5 - Geological Samples */
#define T5 20000
#define P5 3
#define C51_BCET 900
#define C51_WCET 1100
#define C52_BCET 600
#define C52_WCET 900

/* Task 6 - Atmospheric pressure */
#define T6 10000
#define P6 4
#define C61_BCET 500
#define C61_WCET 750

/* Task 7 - Altitude record */
#define P7 4
#define C71_BCET 250
#define C71_WCET 500

/* Task 8 - Temperature record */
#define T8 10000
#define P8 4
#define C81_BCET 500
#define C81_WCET 750

/* Task 9 - Sand Storm Detection */
#define T9 10000
#define P9 4
#define C91_BCET 750
#define C91_WCET 1000


#define C

#endif /* TASKSET_SPEC_H */
