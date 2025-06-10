#include "uart0_int.h"




void UART0_Init()
{
    UBRR0H = 0x00;
    UBRR0L = 0xCF;
    UCSR0A |= (1 << U2X0);      // 2배속
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);  // 폴링일때 셋팅(Tx, Rx 인에이블)

    // 수신 인터럽트 때문에 추가한코드
    UCSR0B |= (1 << RXCIE0);                // 수신 인터럽트 인에이블 
}

void UART0_Transmit(unsigned char data)
{
    while (!(UCSR0A & (1 << UDRE0))); // 송신 가능 대기, UDR이 비어있는지>?
    UDR0 = data;
}

unsigned char UART0_Receive()
{
    while (!(UCSR0A & (1 << RXC0))); // 데이터 수신 대기
    return UDR0;
}

// 출력 스트림 설정 (stdio.h에 있음)
FILE OUTPUT = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);

char rxBuff[100] = {0}; // 수신버퍼
uint8_t rxFlag = 0;     // 수신완료 플래그

// 수신 인터럽트 핸들러
ISR(USART0_RX_vect)
{
    static uint8_t rxHead = 0;  // 수신된 데이터의 인덱스
    uint8_t rxData = UDR0;      // 수신된 데이터
    if(rxData == '\n' || rxData == '\r')
    {
        rxBuff[rxHead] = '\0';  // 수신된 문자열 마지막에 널문자 추가 삽입
        rxHead = 0;             // 인덱스 0으로 초기화
        rxFlag = 1;             // 문자열 수신 플래그 설정
    }
    else
    {
        rxBuff[rxHead] = rxData;// 버퍼에 수신된 데이터 증가
        rxHead++;               // 인덱스 증가
    }
}