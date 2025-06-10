#ifndef __AP_H__
#define __AP_H__

#include "../driver/led8.h"
#include "../driver/main_motor.h"
#include "../driver/sub_motor.h"
#include "../driver/myled.h"
#include "../driver/lcd.h"
// #include "../driver/uart0.h"     // 폴링박식 UART 헤더
#include "../driver/uart0_int.h"    // 인터럽트 UART 헤더



void apMain();



#endif /* __AP_H__ */
