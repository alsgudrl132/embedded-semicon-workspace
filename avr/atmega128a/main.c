#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

// int main(){
//     DDRD = 0xff;
    
//     while(1){
//         PORTD = 0x00;   // 출력 중단
//         _delay_ms(500); // 0.5초동안 대기
//         PORTD = 0xff;   // 출력
//         _delay_ms(500); // 0.5초동안 대기
//     }
// }

#define LED_DDR     DDRD
#define LED_PORT    PORTD

int main() {
    LED_DDR = 0xff;  // D포트를 출력으로 설정
    // LED_DDR = 0b11111111; // 이거나 위의 코드나 같음

    while(1) {
        // 여기서 uint8_t 는 unsigned 8칸짜리 int를 의미한다
        for(uint8_t i = 0; i < 8; i++) {
            LED_PORT |= (1 << i);
            _delay_ms(1000);
        }
    }
}