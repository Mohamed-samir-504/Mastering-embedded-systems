
#include "Lcd/lcd.h"
#include "Keypad/keypad.h"


int main()
{
	
	LCD_INIT();
	//Keypad_init();
	_delay_ms(50);
	LCD_clear_screen();
	LCD_WRITE_CHAR("learn in depth");
	while(1){
		
		}
	}
}


