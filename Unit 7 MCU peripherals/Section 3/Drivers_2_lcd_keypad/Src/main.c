/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "lcd.h"
#include "keypad.h"
#include "7-seg.h"

void clock_init(){

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

uint8_t SEG_numbers[10]={zero,one,two,three,four,five,six,seven,eight,nine};

int main(void)
{
	clock_init();
	LCD_INIT();
	Keypad_init();
	SEG_init();

	LCD_WRITE_STRING("Hello");
	my_wait_ms(1000);
	LCD_clear_screen();
	unsigned char key_pressed;
	while(1){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			SEG_Write_Number(key_pressed-'0');
			break;
		}
	}
}
