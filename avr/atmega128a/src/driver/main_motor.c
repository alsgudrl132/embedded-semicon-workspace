#include "main_motor.h"

void mainMotorInit()
{
    DDRB |= (1 << PB4);                                                             // 선풍기 PB4
    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01) | (1 << CS00); // 타이머컨트롤 참고  // 64 프리스케일러
    OCR0 = 0;                                                                       // 기본 초기값
}

void mainMotorHandler()
{

    mainMotorInit();

    DDRG &= ~((1 << 0) | (1 << 1) | (1 << 2)); // PG포트 0번 1번 2번 버튼
    PORTG |= (1 << 0) | (1 << 1) | (1 << 2);   //

    uint8_t buttonData; // 기존 버튼데이터 소스 이용

    while (1)
    {
        buttonData = PING;
        if ((buttonData & (1 << 2)) == 0) // 0번 포트로 첫번째 버튼 최댓값
        {
            OCR0 = 255;
        }
        else if ((buttonData & (1 << 1)) == 0) // 1번 포트로 두번째 버튼 70프로 값
        {
            OCR0 = 170;
        }
        else if ((buttonData & (1 << 0)) == 0) //  2번 포트로 세번째 버튼 0프로 값
        {
            OCR0 = 0;
        }
    }
}