
#include "Util.h"
#include "MemMap.h"
#include <util/delay.h>

int main(void)
{
	int flag = 0;
    for (int i = 0; i<8; i++)
    {
	    SET_BIT(DDRA,i);
    }
	
	CLEAR_BIT(DDRC,0);
	SET_BIT(PORTC,0);
	
    while (1) 
    {
		if(READ_BIT(PINC,0) == 0){
			if(flag == 0){
				CLEAR_BIT(PORTA,7);
				SET_BIT(PORTA,flag);
				flag++;
			}
			else if(flag == 7){
				SET_BIT(PORTA,flag);
				CLEAR_BIT(PORTA,flag-1);
				flag = 0;
			}
			else{
				SET_BIT(PORTA,flag);
				CLEAR_BIT(PORTA,flag-1);
				flag++;
			}
			
			//do nothing while holding switch
			while(READ_BIT(PINC,0) == 0);
		}
	}
}
		
		

