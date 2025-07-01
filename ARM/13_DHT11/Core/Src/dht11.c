/*
 * dht11.c
 *
 *  Created on: Jul 1, 2025
 *      Author: psh
 */


#include "dht11.h"

void dht11Init(DHT11 *dht, GPIO_TypeDef *port, uint16_t pin)
{
	dht->port = port;	// 시그널선의 포트
	dht->pin = pin;		// 시그널선의 핀번호
}
void dht11GpioMode(DHT11 *dht, uint8_t mode)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	// 출력모드 설정
	if(mode == OUTPUT)
	{
		GPIO_InitStruct.Pin = dht->pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  	GPIO_InitStruct.Pull = GPIO_NOPULL;
	  	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	  	HAL_GPIO_Init(dht->port, &GPIO_InitStruct);
	}
	// 입력모드 설정
	else if(mode == INPUT)
	{
		GPIO_InitStruct.Pin = dht->pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(dht->port, &GPIO_InitStruct);
	}
}
uint8_t dht11Read(DHT11 *dht)
{
	bool ret = true;	// 반환값 변수 (기본값true)

	uint16_t timeTick = 0;	// 시간 측정변수
	uint8_t	pulse[40] = {0};// 40비트 데이터 저장용 변수
	uint8_t	humValue1 = 0, humValue2 = 0;	// 습도 변수
	uint8_t tempValue1 = 0, tempValue2 = 0;	// 온도 변수
	uint8_t parityValue = 0;				// 체크섬 변수

	// 타이머 시작
	HAL_TIM_Base_Start(&htim11);	// for delay_us

	// 통신 신호 전송 (시작)
	dht11GpioMode(dht, OUTPUT);		// output mode 셋팅
	HAL_GPIO_WritePin(dht->port, dht->pin, GPIO_PIN_RESET);
	HAL_Delay(20);					// 18ms이상 대기
	HAL_GPIO_WritePin(dht->port, dht->pin, GPIO_PIN_SET);
	delay_us(30);					// 20~40us 대기

	dht11GpioMode(dht, INPUT);		// output mode -> input mode로 변경
	__HAL_TIM_SET_COUNTER(&htim11, 0);
	while(HAL_GPIO_ReadPin(dht->port, dht->pin) == GPIO_PIN_RESET)
	{
		if(__HAL_TIM_GET_COUNTER(&htim11) > 100)
		{
			printf("Time OUT LOW !!\r\n");
			break;
		}
	}

	__HAL_TIM_SET_COUNTER(&htim11, 0);
	while(HAL_GPIO_ReadPin(dht->port, dht->pin) == GPIO_PIN_SET)
	{
		if(__HAL_TIM_GET_COUNTER(&htim11) > 100)
		{
			printf("Time OUT HIGH !!\r\n");
			break;
		}
	}

	// 데이터 수신
	for(uint8_t i = 0; i < 40; i++)
	{
		while(HAL_GPIO_ReadPin(dht->port, dht->pin) == GPIO_PIN_RESET); // LOW 50us 대기

		__HAL_TIM_SET_COUNTER(&htim11, 0);
		while(HAL_GPIO_ReadPin(dht->port, dht->pin) == GPIO_PIN_SET)
		{
			timeTick = __HAL_TIM_GET_COUNTER(&htim11);	// High신호 시간 측정

			// 신호 길이에 따른 0, 1 구분
			if(timeTick > 20 && timeTick < 30)
			{
				pulse[i] = 0;
			}
			else if(timeTick > 65 && timeTick < 85)
			{
				pulse[i] = 1;
			}
		}
	}

	HAL_TIM_Base_Stop(&htim11);

	// 온습도 데이터 처리
	for(uint8_t i = 0; i < 8; i++){humValue1 = (humValue1 << 1) + pulse[i];}
	for(uint8_t i = 8; i < 16; i++){humValue2 = (humValue2 << 1) + pulse[i];}
	for(uint8_t i = 16; i < 24; i++){tempValue1 = (tempValue1 << 1) + pulse[i];}
	for(uint8_t i = 24; i < 32; i++){tempValue2 = (tempValue2 << 1) + pulse[i];}
	for(uint8_t i = 32; i < 40; i++){parityValue = (parityValue << 1) + pulse[i];}

	// 구조체에 온습도 데이터 입력
	dht->temperature = tempValue1;	// 온도 데이터 저장
	dht->humidity = humValue1;		// 습도 데이터 저장

	// 데이터 무결성 검증
	uint8_t checkSum = humValue1 + humValue2 + tempValue1 + tempValue2;
	if(checkSum != parityValue)
	{
		printf("Check Sum Error \n\r");
		ret = false;
	}


	return ret;
}
