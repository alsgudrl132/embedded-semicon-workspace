#include "led.h"

// // LED출력 함수
// void GPIO_Output(uint8_t data) {    // LED 포트에 8비트 데이터를 매개변수로 받음
//     LED_PORT = data;    // 매개변수를 통해서 받은 데이터를 LED포트에 대입함
// }

// // LED 초기화 함수
// void ledInit() {
//     LED_DDR = 0xff; // 포트D의 모든 핀을 출력으로 설정
// }

// // 이동 함수
// void ledShift(uint8_t i, uint8_t *data) { // 포인터 선언
//     *data = (1 << i) | (1 << (7-i));
// }

// void ledInit(LED *led) { // 매개변수로 포인터 변수선언
//     *(led->port - 1) |= (1 << led->pinNumber);
//     // 데이터시트상 DDR 레지스터는 PORT레지스터보다 1 낮게 위치하므로
//     // *(led->port - 1)를 이용해서 PORT에서 DDR로 접근
//     // |= (1 << led->pinNumber)를 OR연산을 통해서
//     // led->pinNumber로 지정된 포트를 출력으로 설정
// }
void ledInit() {
    DDRD = 0xFF;
}
// void ledOn(LED *led) {
//     // 해당 핀 (내가 원하는 자리)을 HIGH로 설정해서 LED ON
//     *(led->port) |= (1 << led->pinNumber);
// }

void ledOn() {
    PORTD = 0xff;
}
void ledOff(LED *led) {
    // 해당 핀 (내가 원하는 자리)을 LOW로 설정해서 LED OFF
    *(led->port) &= ~(1 << led->pinNumber);
}
void ledRightShift(LED led) {
    for(uint8_t i = 0; i < 8; i++) {
        led.pinNumber = i;
        ledInit(&led);
        ledOn(&led);
        _delay_ms(200);
    }

    for(uint8_t i = 0; i < 8; i++) {
        led.pinNumber = i;
        ledInit(&led);
        ledOff(&led);
        _delay_ms(200);
    }
}

void ledLeftShift(LED led) {
    for(int8_t i = 7; i >= 0; i--) {
        led.pinNumber = i;
        ledInit(&led);
        ledOn(&led);
        _delay_ms(200);
    }

    for(int8_t i = 7; i >= 0; i--) {
        led.pinNumber = i;
        ledInit(&led);
        ledOff(&led);
        _delay_ms(200);
    }
}