#include "ap.h"

void apInit() {
    
}

void apMain() {
    while (1)
    {
        LED_DDR = 0xff;

        // 버튼 관련 변수선언 (기능별 분류)
        BUTTON btnOn;
        BUTTON btnOff;
        BUTTON btnToggle;

        buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON); // 변수주소, DDR주소, PIN주소, 0번핀
        buttonInit(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
        buttonInit(&btnToggle, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);

        while (1)
        {
            if (buttonGetState(&btnOn) == RELEASED) {
                LED_PORT = 0xff;
            }
            if (buttonGetState(&btnOff) == RELEASED) {
                LED_PORT = 0x00;
            }
            if (buttonGetState(&btnToggle) == RELEASED) {
                LED_PORT ^= 0xff;      // ^모양은 반전이다
            }
        }
    }
    
}