#include "sub_motor.h"

// 전역 변수 정의
uint8_t isSubMotorRunning = 0;
uint16_t currentPwm = 250;
uint8_t isIncreasing = 1;

ISR(INT5_vect)
{
    isSubMotorRunning = 0;
}

void subMotorInit()
{
    sei(); // 전역 인터럽트 허용

    // 인터럽트 설정
    EICRB |= (1 << ISC51);
    EICRB &= ~(1 << ISC50);
    EICRB |= (1 << ISC41);
    EICRB &= ~(1 << ISC40);
    EIMSK &= ~(1 << INT5);

    // 버튼 입력 설정 (풀업)
    BTN_SUB_MOTOR_DDR &= ~((1 << BTN_SUB_MOTOR_START) | (1 << BTN_SUB_MOTOR_STOP));
    BTN_SUB_MOTOR_PORT |= ((1 << BTN_SUB_MOTOR_START) | (1 << BTN_SUB_MOTOR_STOP));

    // PWM 출력 설정
    SUB_MOTOR_DDR |= (1 << PB5);
    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10);
    ICR1 = 4999;

    OCR1A = currentPwm; // 시작 시 PWM 설정
}

void handleSubMotor()
{
    // 시작 버튼 눌림 (디바운싱)
    if (isMainMotorRunning == 0)
    {
        return;
    }

    if (!(BTN_SUB_MOTOR_PIN & (1 << BTN_SUB_MOTOR_START)))
    {
        _delay_ms(20);

        if (!(BTN_SUB_MOTOR_PIN & (1 << BTN_SUB_MOTOR_START)))
        {
            isSubMotorRunning = 1;
        }
    }

    // 정지 버튼 눌림 (디바운싱)
    if (!(BTN_SUB_MOTOR_PIN & (1 << BTN_SUB_MOTOR_STOP)))
    {
        _delay_ms(20);
        if (!(BTN_SUB_MOTOR_PIN & (1 << BTN_SUB_MOTOR_STOP)))
        {
            isSubMotorRunning = 0;
        }
        if (OCR0 == 255)
        {
            ledtwo();
        }
        else
        {
            ledone();
        }
    }

    // 회전 상태
    if (isSubMotorRunning)
    {
        if (isIncreasing)
        {
            currentPwm += 5;
            if (OCR0 == 255)
            {
                ledtwo();
            }
            else
            {
                ledone();
            }
            if (currentPwm >= 500)
            {
                currentPwm = 500;
                isIncreasing = 0;
            }
        }
        else
        {
            currentPwm -= 5;
            if (OCR0 == 255)
            {
                ledtwo();
            }
            else
            {
                ledone();
            }
            if (currentPwm <= 250)
            {
                currentPwm = 250;
                isIncreasing = 1;
            }
        }

        OCR1A = currentPwm;
        _delay_ms(70);
    }
    else
    {
        OCR1A = 0; // PWM 정지
    }
}