#include "led8.h"
void led8Init()
{
    DDRD = 0xff;        // LED PORT를 출력으로 설정
}

void ledzero()
{
    PORTD = 0x00;       // LED가 빛이 안들어오게 설정
}

void ledone()
{
    if (isSubMotorRunning)      //LED가 서브모터가 돌고있다면 깜빡이도록 설정
    {                           //그렇지 않다면 1f로 5칸만 켜지게 설정
        LED_PORT = 0x1f;
        _delay_ms(300);
        LED_PORT = 0x00;
    }
    else                        
    {
        PORTD = 0x1f;
    }
}

void ledtwo()
{
   if (isSubMotorRunning)       //LED가 서브 모터가 돌고 있다면 깜빡이도록 설정
    {                           //그렇지 않다면 ff로 다 켜지게 설정
        LED_PORT = 0xff;
        _delay_ms(300);
        LED_PORT = 0x00;
    }
    else
    {
        PORTD = 0xff;
    }
}