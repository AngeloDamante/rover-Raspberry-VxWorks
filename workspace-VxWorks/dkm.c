#include "lib/GPIOLib.h"
#include "lib/l298n.h"
#include "utils.h"
#include <unistd.h>

void test_motor()
{
    init_shield();

    while (1)
    {
        right_rotate();
        msleep(450);

        forward();
        // msleep(300);
        msleep(400);

        stop_vehicle();
    }
}

void start(void)
{
    test_motor();
}