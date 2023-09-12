
#include <util/delay.h>
#include "GPIO_Driver.h"
#include "USART_Driver.h"
#include "lcd.h"

char ch  ;

void USART_IRQ(void)
{
	MCAL_USART_ReceiveData(&ch , Disable) ;
	LCD_GOTO_XY(2,0);
	LCD_WRITE_CHAR(ch);
	_delay_ms(2000);
	LCD_clear_screen();
}


char number [10]={ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,'8' , '9' } ;
	
int main(void)
{
    /* Replace with your application code */
    LCD_INIT();
    USART_CONFIG usart_cfg;
	
	usart_cfg.Baud_Rate = USART_BAUD_RATE_9600;
	usart_cfg.Mode = USART_MODE_TX_RX;
	usart_cfg.Operating_Mode = USART_Operating_Mode_Asynch_Normal;
	usart_cfg.Data_Bits = USART_DATA_BITS_8;
	usart_cfg.Stop_Bits = USART_STOP_BITS_1;
	usart_cfg.Parity = USART_PARITY_NONE;
	usart_cfg.IRQ_EN = USART_IRQ_ENABLE_RX;
	usart_cfg.P_IRQ_CALL = USART_IRQ;
    
	MCAL_USART_Init(&usart_cfg);
	
	int i =0;
	
    while (1)
    {
	    LCD_WRITE_CHAR(number [i]);
	    i++;
	    if(i==10){
			i=0 ;
		}
	    _delay_ms(1000) ;
	    LCD_clear_screen();
    }
}

