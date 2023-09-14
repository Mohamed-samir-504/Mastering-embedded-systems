
#include <util/delay.h>
#include "GPIO_Driver.h"
#include "USART_Driver.h"
#include "SPI_Driver.h"
#include "lcd.h"


//#define SPI_Act_As_Master
#define SPI_Act_As_Slave


char ch ;

void SPI_Call_INIT(void)
{
	#ifdef SPI_Act_As_Slave
	MCAL_SPI_ReceiveData(&ch,Enabled);
	MCAL_USART_SendData( &ch , Enable);
	#endif
}


	
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
	usart_cfg.IRQ_EN = USART_IRQ_ENABLE_NONE;
	usart_cfg.P_IRQ_CALL = NULL;
    
	MCAL_USART_Init(&usart_cfg);
	
	SPI_CONFIG SPI_Conf ;
	
	SPI_Conf.BaudRate_Prescalers = SPI_BaudRate_Prescalers_4 ;
	SPI_Conf.Data_Order = SPI_Data_Order_MSB_Transmitted_First ;
	SPI_Conf.IRQ_EN = SPI_IRQ_ENABLE_Enable ;
	SPI_Conf.P_IRQ_CALL = SPI_Call_INIT ;
	SPI_Conf.Phase = SPI_Phase_Data_Latched_On_First_Clock ;
	SPI_Conf.Polarity = SPI_Polarity_Low_level_idle_state ;
	SPI_Conf.Speed_Communication = SPI_Speed_Communication_Normal ;
	
	#ifdef SPI_Act_As_Master
	SPI_Conf.MODE = SPI_MODE_Master ;
	MCAL_SPI_Set_Master_Pin();
	#endif
	
	#ifdef SPI_Act_As_Slave
	SPI_Conf.MODE = SPI_MODE_Slave ;
	MCAL_SPI_Set_Slave_Pin() ;
	#endif
	
	MCAL_SPI_Init(&SPI_Conf) ;
	
	
	while (1)
	{
		#ifdef SPI_Act_As_Master
		MCAL_USART_ReceiveData(&ch , Enable) ;
		MCAL_USART_SendData( &ch , Enable);
		MCAL_SPI_SendData( &ch ,Enabled);
		#endif
	}
}

