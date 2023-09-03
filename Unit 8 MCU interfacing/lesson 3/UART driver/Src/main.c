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
#include "STM32F103C6_EXTI_driver.h"
#include "STM32F103C6_RCC_driver.h"
#include "STM32F103C6_USART_driver.h"

int flag = 0;

void clock_init(){

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

unsigned char ch;

void test_IRQ(void){
	MCAL_USART_Receive_Data(USART1, &ch, disable);
	MCAL_USART_Send_Data(USART1, &ch, enable);
}

int main(void)
{
	clock_init();


	USART_config usart_cfg;

	usart_cfg.Baud_rate = USART_BaudRate_115200;
	usart_cfg.HW_Flow_Control = USART_Flow_Control_NONE;
	usart_cfg.IRQ_Enable = USART_IRQ_ENABLE_RXNEIE;
	usart_cfg.P_IRQ_Callback = test_IRQ;
	usart_cfg.Parity = USART_Parity_NONE;
	usart_cfg.Payload_length = USART_Payload_Length_8;
	usart_cfg.Stop_bits = USART_Stop_bit_1;
	usart_cfg.USART_MODE = USART_MODE_TX_RX;

	MCAL_USART_Init(USART1, &usart_cfg);
	MCAL_USART_GPIO_Set_Pins(USART1);

	while(1){

	}
}
