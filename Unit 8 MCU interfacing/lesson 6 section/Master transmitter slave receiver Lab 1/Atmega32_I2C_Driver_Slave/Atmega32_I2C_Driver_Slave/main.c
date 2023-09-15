

#include <avr/io.h>
#include <util/delay.h>
#include "I2C _Driver.h"

int main(void)
{
	DDRA = 0xFF;
	I2C_Set_Address(0b11010000);
	
	
	while (1)
	{
		PORTA = I2C_Read(1);
	}
}

