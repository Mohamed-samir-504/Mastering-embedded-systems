
//#include <util/delay.h>
#include "GPIO_Driver.h"
#include "USART_Driver.h"
#include "lcd.h"

int main(void)
{
    /* Replace with your application code */
    char x[200];
    LCD_INIT();
    LCD_clear_screen();
 
    LCD_WRITE_STRING("UART test");
    
    USART_CONFIG usart_cfg;
	usart_cfg.Baud_Rate = USART_BAUD_RATE_9600;
	usart_cfg.Mode = USART_MODE_TX_RX;
	usart_cfg.Operating_Mode = USART_Operating_Mode_Asynch_Normal;
	usart_cfg.Data_Bits = USART_DATA_BITS_8;
	usart_cfg.Stop_Bits = USART_STOP_BITS_1;
	usart_cfg.Parity = USART_PARITY_NONE;
    
	MCAL_USART_Init(&usart_cfg);
    MCAL_USART_Send_String("Mohamed Samir");
    LCD_GOTO_XY(2,0);
    while (1)
    {
	    MCAL_USART_Receive_String(&x);
	    LCD_WRITE_STRING(x);
    }
}

