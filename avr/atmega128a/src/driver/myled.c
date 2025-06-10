#include <avr/io.h>
#include "myled.h"


void myledInit(void)
{
    DDRA = 0xFF;        // PORTA 전체를 출력으로 설정
    PORTA = 0xff;       // PORTA 전체를 0으로 초기화
}


// 숫자 0~4 출력용 FND 함수들

void segzero()
{
    PORTA = ~0x3F;
}

void segone()
{
    PORTA = ~0x06;
}

void segtwo()
{
    PORTA = ~0x5B;
}

void segthree()
{
    PORTA = ~0x4F;
}

void segfour()
{
    PORTA = ~0x66;
}