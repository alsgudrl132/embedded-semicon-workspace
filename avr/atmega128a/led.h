#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

// void GPIO_Output(uint8_t data);
// void ledInit();
// void ledShift(uint8_t i, uint8_t *data);

typedef struct {
    volatile uint8_t *port;
    uint8_t          pinNumber;
} LED;

void ledInit(LED *led);
void ledOn(LED *led);
void ledOff(LED *led);
void ledLeftShift(LED led);
void ledRightShift(LED led);
