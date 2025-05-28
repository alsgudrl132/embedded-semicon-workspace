#include "led.h";

// int main(){
//     DDRD = 0xff;
    
//     while(1){
//         PORTD = 0x00;   // 출력 중단
//         _delay_ms(500); // 0.5초동안 대기
//         PORTD = 0xff;   // 출력
//         _delay_ms(500); // 0.5초동안 대기
//     }
// }

// #define LED_DDR     DDRD
// #define LED_PORT    PORTD

// int main() {
//     LED_DDR = 0xff;  // D포트를 출력으로 설정
//     // LED_DDR = 0b11111111; // 이거나 위의 코드나 같음

//     while(1) {
//         // 여기서 uint8_t 는 unsigned 8칸짜리 int를 의미한다
//         for(uint8_t i = 0; i < 8; i++) {
//             LED_PORT |= (1 << i);
//             _delay_ms(1000);
//         }
//     }
// }

// #define LED_DDR DDRD
// #define LED_PORT PORTD
// int main() {
//     DDRD = 0xff;
    
//     while(1) {
//         for(uint8_t i = 0; i < 8; i++) {
//             LED_PORT |= (1 << i);
//             _delay_ms(200);
//         }
//         for(uint8_t i = 0; i < 8; i++) {
//             LED_PORT &= ~(1 << i);
//             _delay_ms(200);
//         }
//     }
// }

// #define LED_DDR     DDRD
// #define LED_PORT    PORTD

// int main() {
//     LED_DDR = 0xff;
    
//     while (1) {
//         // LED를 바깥쪽에서 가운데로 이동하기
//         for(uint8_t i = 0; i < 4; i++) {
//             LED_PORT = ((0x01 << i) | (0x80 >> i)); 
//             // 0000 0001
//             // 1000 0000
//             // 1000 0001
//             if(LED_PORT == 0x18) {
//                 _delay_ms(0);
//             }else {
//                 _delay_ms(500);
//             }
//             // _delay_ms(500);
//         }

//         // LED를 가운데에서 바깥쪽으로 이동하기
//         for(uint8_t i = 0; i < 4; i++) {
//             LED_PORT = ((0x08 << i) | (0x10 >> i));
//             // 0000 1000
//             // 0001 0000
//             // 0001 1000
//             _delay_ms(500);
//         }

//     }
    
// }

// #define LED_DDR DDRD
// #define LED_PORT PORTD
// int8_t mask = 0x00;
// int main() {
//     DDRD = 0xff;
    
//     while(1) {
//         for(uint8_t i = 0; i < 8; i++) {
//             LED_PORT |= (1 << i);
//             _delay_ms(200);
//         }
//         for(uint8_t i = 0; i < 8; i++) {
//             LED_PORT &= ~(0x00 >> i);
//             _delay_ms(200);
//         }
//         /*
//             1111 1111
//             0111 1111
//             0011 1111
//             0001 1111
//         */
//     }
// }


// void GPIO_Output(uint8_t data);
// void ledInit();
// void ledShift(uint8_t i, uint8_t *data);

// int main() {
//     ledInit();

//     uint8_t ledData = 0x81; // 1000 0001
    
//     while (1)
//     {
//         for(uint8_t i = 0; i < 8; i++) {
//             ledShift(i, &ledData);
//             GPIO_Output(ledData);
//             _delay_ms(400);
//         }
//     }
    
// }

int main() {
    LED led;
    led.port = &PORTD;
    // led.pinNumber = 0;


    while (1) {
        // ledOn(&led);
        // _delay_ms(500);
        // ledOff(&led);
        // _delay_ms(500);
        for(uint8_t i = 0; i < 8; i++) {
            led.pinNumber = i;
            ledInit(&led);
            ledOn(&led);
            _delay_ms(500);
            ledOff(&led);
            _delay_ms(500);
        }
    }
}