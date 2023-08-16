
#include "Lcd/lcd.h"
#include "Keypad/keypad.h"


int main()
{
	
	LCD_INIT();
	Keypad_init();
	_delay_ms(50);
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
				break;
		}
	}
}


