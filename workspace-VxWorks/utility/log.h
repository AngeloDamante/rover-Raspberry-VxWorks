/*
 * log.h
 * Header to define log utility functions.
 * 
 * @Author: AngeloDamante, KevinMaggi
 * @mail: angelo.damante16@gmail.com, kevin.maggi@stud.unifi.it
 * @Github: https://github.com/AngeloDamante, https://github.com/KevinMaggi
 * @Special_Tanks_to: Andrea Puccia, Lorenzo Nuti, Lorenzo Mandelli
*/

#ifndef LOG_H
#define LOG_H

/* includes */
#include <vxWorks.h>

/* Structure to store logs */
MSG_Q_ID initLogger();

/* Utility functions */
void logEvent(MSG_Q_ID logQueue, char * transition);
void saveLog(MSG_Q_ID logQueue, char * fileName);


#endif /* LOG_H */
