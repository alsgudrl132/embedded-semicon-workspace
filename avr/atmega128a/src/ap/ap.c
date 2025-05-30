#include "ap.h"

void apInit() {
    
}

// void apMain() {
//     while (1)
//     {
//         LED_DDR = 0xff;

//         // 버튼 관련 변수선언 (기능별 분류)
//         BUTTON btnOn;
//         BUTTON btnOff;
//         BUTTON btnToggle;

//         buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON); // 변수주소, DDR주소, PIN주소, 0번핀
//         buttonInit(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
//         buttonInit(&btnToggle, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);

//         while (1)
//         {
//             if (buttonGetState(&btnOn) == RELEASED) {
//                 LED_PORT = 0xff;
//             }
//             if (buttonGetState(&btnOff) == RELEASED) {
//                 LED_PORT = 0x00;
//             }
//             if (buttonGetState(&btnToggle) == RELEASED) {
//                 LED_PORT ^= 0xff;      // ^모양은 반전이다
//             }
//         }
//     }
// }

ISR(INT4_vect) {
    ledOn();
}

ISR(INT5_vect) {
    PORTD = 0x00;
}

void apMain() {
    sei();          // 전역 인터럽트 Enable

    // EICRB = 0x0E;   // INT4 하강엣지, INT5 상승엣지
    EICRB |= (1<<ISC51) | (1<<ISC50) | (1<<ISC41); // 16진수로 계산하지말고 데이터시트에 나온 그림에 맞는 숫자자리는 1로 만들면된다.
  
    // EIMSK = 0x30;   // INT4, INT5 Interrput Enable
    EIMSK |= (1<<INT5) | (1<<INT4);                // 16진수로 계산하지말고 데이터시트에 나온 그림에 맞는 숫자자리는 1로 만들면된다.

    ledInit();    

    while (1)
    {
        
    }
    
}