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

// int main() {
//     LED led;
//     led.port = &PORTD;
//     led.pinNumber = 0;


//     while (1) {
//         ledOn(&led);
//         _delay_ms(500);
//         ledOff(&led);
//         _delay_ms(500);
//     }
// }

// int main() {
//     LED led;
//     led.port = &PORTD;

//     while (1) {
//         ledLeftShift(led);
//         // ledRightShift(led);
//     }
// }

// int main() {
//     uint8_t fndNumber[] = {
//         0x3F,
//         0x06,
//         0x5B,
//         0x4F,
//         0x66,
//         0x6D,
//         0x7D,
//         0x27,
//         0x7F,
//         0x67
//     };
        
//     // int count = 0;  // C언어에서는 4바이트가 맞지만 펌웨어에서는 2바이트
//     int16_t count = 0;
//     DDRA = 0xff;
//     while(1) {
//         {
//             PORTA = fndNumber[count];
//             count = (count + 1) % 10;
//             _delay_ms(500);
//         }
//     }
// }

// int main() {
//     uint8_t fndNumber = 0x3F;
//     DDRB = 0xff;
//     DDRC = 0x0F;
//     while(1) {
//         PORTB = fndNumber;
//         _delay_ms(500); 
//     }
// }

// #define FND_DATA_DDR    DDRB    // 실질적인 데이터 포트
// #define FND_SELECT_DDR  DDRC    // 디지트 선택 포트
// #define FND_DATA_PORT   PORTB
// #define FND_SELECT_PORT PORTC

// void FND_Display(uint16_t data);

// int main() {
//     FND_DATA_DDR = 0xFF;    // 데이터 포트 출력으로 설정 (PORTB : 0~7)
//     FND_SELECT_DDR = 0xFF;  // 디지트 선택 포트 출력 설정 (PORTC : 0~3)
//     FND_SELECT_PORT = 0x00; // 디지트 선택 포트 초기값 0 설정

//     uint16_t count = 0;     // 16bit(0~65535)
//     uint32_t timeTick = 0;  // 32bit(0~42억 언저리)
//     uint32_t prevTime = 0;
    
//     while(1) {
//         FND_Display(count);
//         if(timeTick - prevTime >= 100) { // 100ms가 지날때 마다 count값을 1 증가
//             prevTime = timeTick;        // 현재시간을 prevTime에 저장
//             count++;                    
//         }
//         _delay_ms(1);                   // 1밀리 대기
//         timeTick++;                     // timeTick을 1ms 증가 시킴
//     }
// }

// void FND_Display(uint16_t data) {   // FND에 숫자를 표출하는 함수 표현할수있는수가 9999까지이기때문에 16비트로 선언
//     static uint8_t position = 0;    // 디지트 포지션
//     uint8_t fndData[10] = {
//         0x3F,
//         0x06,
//         0x5B,
//         0x4F,
//         0x66,
//         0x6D,
//         0x7D,
//         0x27,
//         0x7F,
//         0x67
//     };

//     switch (position)   // 조건신(판단식) ==> 정수값
//     {
//     case 0:
//         // 첫번째 자리의 FND데이터를 출력하기 위해 0번핀 LOW, 1, 2, 3번핀 HIGH
//         FND_SELECT_PORT &= ~(1 << 0);                       // 0번핀 LOW
//         FND_SELECT_PORT |= (1 << 1) | (1 << 2) | (1 << 3);  // 1,2,3번핀 HIGH
//         // 입력된 데이터의 천의 자리를 구해서 해당 FND데이터를 출력
//         FND_DATA_PORT = fndData[data/1000];
//         break;
//     case 1:
//         // 첫번째 자리의 FND데이터를 출력하기 위해 1번핀 LOW, 0, 2, 3번핀 HIGH
//         FND_SELECT_PORT &= ~(1 << 1);                       // 1번핀 LOW
//         FND_SELECT_PORT |= (1 << 0) | (1 << 2) | (1 << 3);  // 0,2,3번핀 HIGH
//         // 입력된 데이터의 백의 자리를 구해서 해당 FND데이터를 출력
//         FND_DATA_PORT = fndData[data/100%10];
//         break;
//     case 2:
//         // 첫번째 자리의 FND데이터를 출력하기 위해 2번핀 LOW, 0, 1, 3번핀 HIGH
//         FND_SELECT_PORT &= ~(1 << 2);                       // 2번핀 LOW
//         FND_SELECT_PORT |= (1 << 0) | (1 << 1) | (1 << 3);  // 0,1,3번핀 HIGH
//         // 입력된 데이터의 백의 자리를 구해서 해당 FND데이터를 출력
//         FND_DATA_PORT = fndData[data/10%10];
//         break;
//     case 3:
//         // 첫번째 자리의 FND데이터를 출력하기 위해 3번핀 LOW, 0, 1, 2번핀 HIGH
//         FND_SELECT_PORT &= ~(1 << 3);                       // 3번핀 LOW
//         FND_SELECT_PORT |= (1 << 0) | (1 << 1) | (1 << 2);  // 0,1,2번핀 HIGH
//         // 입력된 데이터의 백의 자리를 구해서 해당 FND데이터를 출력
//         FND_DATA_PORT = fndData[data%10];
//         break;
//     }
//     position++;     // 다음 자리로 이동하기 위해서 position을 증가
//     position %= 4;  // 4자리수 출력한후에 다시 첫번째로 돌아가기 위함
// }

// Button PORTG에 연결 2,3,4
// Pull-Up 저항 연결

// int main() {
//     DDRD = 0xff;        // LED Bar 연결된곳
    
//     DDRG &= ~((1 << 2)|(1 << 3)|(1 << 4));  // PORTG 2번핀을 (0) 입력으로 설정
    
//     while (1)
//     {
//         if(PING & (1<<2)){
//             PORTD = 0x00;
//         }
//         else {
//             PORTD = 0xff;
//         }
//     }
// }

int main() {
    DDRD = 0xff;        // LED Bar 연결된곳
    DDRG &= ~((1 << 2)|(1 << 3)|(1 << 4));  // PORTG 2번핀을 (0) 입력으로 설정
    LED led;
    led.port = &PORTD;
    
    uint8_t buttonData;
    while (1)
    {
        buttonData = PING;
        if((buttonData & (1 << 2)) == 0) {
            PORTD = 0xff;
        }
        if((buttonData & (1 << 3)) == 0) {
            ledLeftShift(led);
        }
        if((buttonData & (1 << 4)) == 0) {
            PORTD = 0x00;
        }
    }
    
}