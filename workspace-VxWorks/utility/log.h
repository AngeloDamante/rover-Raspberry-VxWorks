#ifndef LOG_H
#define LOG_H

#include <vxWorks.h>

MSG_Q_ID initLogger();

void logEvent(MSG_Q_ID logQueue, char * transition);

void saveLog(MSG_Q_ID logQueue, char * fileName);


#endif /* LOG_H */
