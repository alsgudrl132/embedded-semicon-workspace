#include "ap.h"
void apMain()
{
    // LCD_Init();
    // LCD_GotoXY(0,0);
    // LCD_WriteString("Hello LCD");
    // LCD_GotoXY(1,0);
    // LCD_WriteString("Hello AVR");

    // char buff[30];
    // sprintf(buff, "Hello ATmega128a");
    // LCD_WriteStringXY(0, 0, buff);
    // uint16_t count = 0;
    // while (1)
    // {
    //     sprintf(buff, "Count : %d", count++);
    //     LCD_WriteStringXY(1, 2, buff);
    //     _delay_ms(100);
    // }

    extern FILE OUTPUT;
    extern uint8_t rxFlag;
    extern char rxBuff[100];

    UART0_Init();
    stdout = &OUTPUT;
    
    sei();

    while (1)
    {
        if(rxFlag == 1)     // 문자열 수신이 완료된 경우
        {
            rxFlag = 0;     // 문자열 수신 플래그 초기화
            printf(rxBuff); // 수신된 문자열 출력
        }    
    }
    
}