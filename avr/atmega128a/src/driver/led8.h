 #ifndef __LED8_H__
 #define __LED8_H__
 
 #include "../common/def.h"
 #include "../ap/ap.h"

 #define LED_DDR     DDRD
 #define LED_PORT    PORTD

void ledzero();
void ledone();
void ledtwo();
void led8Init();

 #endif /* __LED8_H__ */