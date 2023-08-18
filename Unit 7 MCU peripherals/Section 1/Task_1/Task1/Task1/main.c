

#include "MemMap.h"
#include "Util.h"
#include <util/delay.h>

int main(void)
{
	//make all portA pins as output
    for (int i = 0; i<8; i++)
    {
		SET_BIT(DDRA,i);
    }
	
    while (1) 
    {
		for (int i = 0; i<8; i++)
		{
			SET_BIT(PORTA,i);
			_delay_ms(500);
		}
		
		_delay_ms(1000);
		for (int i = 7; i>=0; i--)
		{
			CLEAR_BIT(PORTA,i);
			_delay_ms(500);
		}
		
    }
}

