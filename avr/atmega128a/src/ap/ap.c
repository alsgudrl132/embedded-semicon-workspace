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

    UART0_Init();
    while (1)
    {
        UART0_Transmit(UART0_Receive());
    }
    
}