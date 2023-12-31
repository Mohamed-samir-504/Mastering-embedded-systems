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

#include "STM32F103C6_GPIO_driver.h"
#include "STM32F103x6.h"

void clock_init(){

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void GPIOA_init(){

	GPIO_PinConfig_t Pincfg;

    //PA1 floating input
	Pincfg.GPIO_PinNumber = GPIO_PIN1;
	Pincfg.GPIO_MODE=GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_Init(GPIOA, &Pincfg);

	/* PA13 floating input */
	Pincfg.GPIO_PinNumber = GPIO_PIN13;
	Pincfg.GPIO_MODE=GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_Init(GPIOA, &Pincfg);

}

void GPIOB_init(){
	GPIO_PinConfig_t Pincfg;

	/*PB1 output push_pull*/
	Pincfg.GPIO_PinNumber = GPIO_PIN1;
	Pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	Pincfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &Pincfg);

	/*PB13 output push_pull*/
	Pincfg.GPIO_PinNumber = GPIO_PIN13;
	Pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	Pincfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &Pincfg);
}

void my_wait (int x)
{
	unsigned int i , j ;
	for (i= 0 ; i<x ; i++)
		for (j= 0 ; j<255 ; j++);
}

int main(void)
{
	clock_init();
	GPIOA_init();
	GPIOB_init();

	while(1){

		//PA1 is connected as external PUR (default value is 1)
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN1) == 0)
		{
			MCAL_GPIO_togglePin(GPIOA, GPIO_PIN1);
			while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN1) == 0);
		}

		//PA1 is connected as external PDR (default value is 0)
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN13) == 1)
		{
			MCAL_GPIO_togglePin(GPIOA, GPIO_PIN13);
		}

		my_wait(1);

	}


}
