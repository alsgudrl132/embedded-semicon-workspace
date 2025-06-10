#ifndef __MAIN_MOTOR_H__
#define __MAIN_MOTOR_H__

#include "../ap/ap.h"

uint8_t isMainMotorRunning;

void mainMotorInit();
void mainMotorHandler();

#endif /* __MAIN_MOTOR_H__ */