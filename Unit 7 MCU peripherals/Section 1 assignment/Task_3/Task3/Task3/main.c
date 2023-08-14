#include "Util.h"
#include "MemMap.h"
#include <util/delay.h>


int main(void)
{
    CLEAR_BIT(DDRD,0);
	//activate as pull down(default value is 0)
    CLEAR_BIT(PORTD,0);
	
    SET_BIT(DDRD,4);
	
    while (1)
    {
	    if (READ_BIT(PIND,0) == 1)
	    {
		    
		    SET_BIT(PORTD,4);
		    _delay_ms(1000);
		    CLEAR_BIT(PORTD,4);
		    
	    }
    }
}

