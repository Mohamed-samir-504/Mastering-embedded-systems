
#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 8000000UL

#include "STM32F103C6_GPIO_driver.h"
#include "STM32F103x6.h"


#define R0 GPIO_PIN0
#define R1 GPIO_PIN1
#define R2 GPIO_PIN3
#define R3 GPIO_PIN4
#define C0 GPIO_PIN5
#define C1 GPIO_PIN6
#define C2 GPIO_PIN7
#define C3 GPIO_PIN8

#define KEYPAD_PORT GPIOB


void Keypad_init();
unsigned char Keypad_getkey();

#endif /* KEYPAD_H_ */
