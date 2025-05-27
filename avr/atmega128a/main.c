#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

int main(){
    DDRD = 0xff;
    
    while(1){
        PORTD = 0x00;   // 출력 중단
        _delay_ms(500); // 0.5초동안 대기
        PORTD = 0xff;   // 출력
        _delay_ms(500); // 0.5초동안 대기
    }
}
