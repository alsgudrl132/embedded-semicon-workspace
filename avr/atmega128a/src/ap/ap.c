#include "ap.h"

void apInit()
{
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

// ISR(INT4_vect) {
//     ledOn();
// }

// ISR(INT5_vect) {
//     PORTD = 0x00;
// }

// void apMain() {
//     DDRB |= (1 << PB4);  // PB4 (OC0 핀)를 출력으로 설정

//     // Timer0 설정
//     TCCR0 = 0;  // 초기화
//     TCCR0 |= (1 << WGM01);               // CTC 모드
//     TCCR0 |= (1 << COM00);               // Toggle OC0 on compare match
//     TCCR0 |= (1 << CS01) | (1 << CS00);  // 분주비 64 (CS01=1, CS00=1)

//     OCR0 = 499;  // 250Hz 출력 목표

//     while (1) {
//         // 아무것도 안 해도 하드웨어가 알아서 PB4 토글함
//     }
// }

// void apMain() {
//     DDRD = 0xff;
//     PORTD = 0;
//     TCCR0 |= (1<<CS00) | (1<<CS02);

//     TCNT0 =  131;

//     while(1) {
//         while ((TIFR & 0x01) == 0) {

//         }
//         PORTD = ~PORTD;
//         TCNT0 = 131;
//         TIFR = 0x01;
//     }
// }

// void apMain() {
//     DDRB |= (1<<PB4);    // PB4포트만 출력 설정
//     TCCR0 |= (1<<WGM00) | (1<<COM01) | (1<<WGM01) | (1<<CS02);
//     // TCCR0 = 0x6C;    위의 코드와 동일
//     OCR0 = 150;
// }

// 모터가 빠른속도로 돌면 선풍기의 역할이 제대로 안되기때문에 천천히돌도록 OCR1A에 +5씩 주입
// 중간에 멈출수있도록 인터럽트 사용
// 멈춘지점부터 다시회전할수있도록 currentPwm 변수 추가

#define ROTATION_ON 3
#define ROTATION_OFF 4
#define ROTATION_BUTTON_DDR DDRG
#define ROTATION_BUTTON_PIN PING
#define ROTATION_BUTTON_PORT PORTG
#define ROTATION_MOTOR_DDR DDRB
#define ROTATION_MOTOR_PORT PORTB

volatile uint8_t isRunning = 1;
volatile uint16_t currentPwm = 250;
uint8_t directionUp = 1;    // 1이면 증가하는중 0이면 감소하는중

ISR(INT5_vect)
{
    isRunning = 0;
}

void apMain()
{
    sei(); // 전역 인터럽트 허용

    // 인터럽트 설정
    EICRB |= (1 << ISC51); EICRB &= ~(1 << ISC50);
    EICRB |= (1 << ISC41); EICRB &= ~(1 << ISC40);
    EIMSK |= (1 << INT5);

    // 버튼 입력 설정 (풀업)
    ROTATION_BUTTON_DDR &= ~((1 << ROTATION_ON) | (1 << ROTATION_OFF));
    ROTATION_BUTTON_PORT |= ((1 << ROTATION_ON) | (1 << ROTATION_OFF));

    // PWM 출력 설정
    ROTATION_MOTOR_DDR |= (1 << PB5);
    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10);
    ICR1 = 4999;

    OCR1A = currentPwm; // 시작 시 PWM 설정

    while (1)
    {
        // 시작 버튼 눌림
        if (!(ROTATION_BUTTON_PIN & (1 << ROTATION_ON)))
        {
            isRunning = 1;
        }

        // 회전 상태
        if (isRunning)
        {
            if (directionUp)
            {
                currentPwm += 5;
                if (currentPwm >= 500)
                {
                    currentPwm = 500;
                    directionUp = 0;
                }
            }
            else
            {
                currentPwm -= 5;
                if (currentPwm <= 250)
                {
                    currentPwm = 250;
                    directionUp = 1;
                }
            }

            OCR1A = currentPwm;
            _delay_ms(70);
        }
        // 정지 버튼 눌림
        else
        {
            OCR1A = 0; // PWM 정지
        }
    }
}
