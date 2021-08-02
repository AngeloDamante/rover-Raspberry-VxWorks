source SDK/toolkit/wind_sdk_env.linux
$CC -dkm hwLib/gpioLib.c hwLib/l298n.c utility/utils.c utility/mutex.c utility/log.c utility/busySleep.c taskset.c entrypoints.c  mission.c dkm.c -o dkm.o