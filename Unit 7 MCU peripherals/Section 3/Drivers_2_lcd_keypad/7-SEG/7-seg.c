

#include "7-seg.h"


uint16_t SEG_pins[7]={GPIO_PIN9,GPIO_PIN10,GPIO_PIN11,GPIO_PIN12,GPIO_PIN13,GPIO_PIN14,GPIO_PIN15};
uint8_t SEG_Numbers[10]={zero,one,two,three,four,five,six,seven,eight,nine};

extern GPIO_PinConfig_t Pinconfig;

void SEG_init(void)
{
	//Select Mode of Pins as output Push Pull
	Pinconfig.GPIO_MODE	= GPIO_MODE_OUTPUT_PP;
	Pinconfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	for(int i=0;i<7;i++)
	{
		Pinconfig.GPIO_PinNumber = SEG_pins[i];
		MCAL_GPIO_Init(SEG_PORT, &Pinconfig);
	}
}

void SEG_Write_Number(uint8_t num)
{

	SEG_clear();


	for(int i=0;i<7;i++)
		MCAL_GPIO_WritePin(SEG_PORT, SEG_pins[i],(SEG_Numbers[num]>>i)&1);


}
void SEG_clear(void)
{

	for(int i=0;i<7;i++)
		MCAL_GPIO_WritePin(SEG_PORT, SEG_pins[i], GPIO_PIN_RESET);
}

