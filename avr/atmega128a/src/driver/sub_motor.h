#ifndef __SUB_MOTOR_H__
#define __SUB_MOTOR_H__

#include "../ap/ap.h"

// 버튼 관련 매크로 정의
#define BTN_SUB_MOTOR_START 3
#define BTN_SUB_MOTOR_STOP  4
#define BTN_SUB_MOTOR_DDR   DDRG
#define BTN_SUB_MOTOR_PIN   PING
#define BTN_SUB_MOTOR_PORT  PORTG
#define SUB_MOTOR_DDR       DDRB

// 전역 변수 선언
uint8_t isSubMotorRunning;
uint16_t currentPwm;
uint8_t isIncreasing;

// 함수 선언
void subMotorInit(void);
void handleSubMotor(void);

#endif /* __SUB_MOTOR_H__ */