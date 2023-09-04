
#include <avr/io.h>
#include <util/delay.h>

#include "Util.h"
#include "MCAL/UART.h"
#include "HAL/lcd.h"


int main(void)
{
	
    char x;
	char strr[200];
	LCD_INIT();
	LCD_clear_screen();
	_delay_ms(1000);
	LCD_WRITE_STRING("UART test");
	
	UART_init();
	
	LCD_GOTO_XY(2,0);
	UART_SendString("Mohamed samir");
	
    while (1) 
    {
		UART_ReceiveString(strr);
		LCD_WRITE_STRING(strr);
    }
}

