#include "USART_Driver.h"
#include "GPIO_Driver.h"

USART_CONFIG* global_USART_config = NULL;
void (*GP_IRQ_CALL[3])(void);
void MCAL_USART_Init(USART_CONFIG* USART_config ){
	
	global_USART_config = USART_config;
	uint16_t BRR;
	
	if(USART_config->Operating_Mode == USART_Operating_Mode_synch_Master || USART_config->Operating_Mode == USART_Operating_Mode_synch_Slave){
		
		//bit 7 in UCSRC chooses between accessing the UCSRC or UBRRH register (default value 1 -> UCSRC)
		UCSRC |= (1<<7);
		UCSRC |= USART_config->Clock_Polarity;
		//UMSEL BIT (1 for synchronous)
		UCSRC |= (1<<6); 
		
		//Baud rate
		
		BRR = ( FR_CPU/ ( (uint32_t)2 * USART_config->Baud_Rate) ) - 1 ;
		//the reason for typecasting the number to uint32
		//is because it is by default signed int and (signed int)*(unsigned short) will cause problems
		//but (unsigned int)*(unisgned short) = unsigned int
	}
	else if(USART_config->Operating_Mode == USART_Operating_Mode_Asynch_Double_Speed){
		//UMSEL BIT (0 for asynchronous)
		UCSRC |= (1<<7);
		UCSRC &= ~(1<<6);
		//set U2X bit
		USART->UCSRA |= (1<<1);
		
		BRR = ( FR_CPU/ ( (uint32_t)8 * USART_config->Baud_Rate) ) - 1  ;
	}
	else{
		//UMSEL BIT (0 for asynchronous)
		UCSRC |= (1<<7);
		UCSRC &= ~(1<<6);
		//clear U2X bit
		USART->UCSRA &= ~(1<<1);
		
		BRR = ( FR_CPU/ ( (uint32_t)16 * USART_config->Baud_Rate) ) - 1  ;
	}
	
	//configure baud rate
	USART->UBRRL = BRR;
	
	//---------------------------------------------Data bits---------------------------------------------------------
	//UCSZ2 UCSZ1 UCSZ0 Character Size
	//0       0     0         5-bit
	//0       0     1         6-bit
	//0       1     0         7-bit
	//0       1     1         8-bit
	
	//UCSZ2 bit is bit number 2 in UCSRB register
	//UCSZ1 and UCSZ0 are bits number 2,1 in UCSRC register
	
	UCSRC |= (1<<7);
	switch(USART_config->Data_Bits){
		case USART_DATA_BITS_5:
		{
			USART->UCSRB &= ~(1<<2);
			UCSRC &= ~(3<<1);
			break;	
		}
		case USART_DATA_BITS_6:
		{
			USART->UCSRB &= ~(1<<2);
			UCSRC &= ~(1<<2);
			UCSRC |= (1<<1);
			break;
		}
		case USART_DATA_BITS_7:
		{
			USART->UCSRB &= ~(1<<2);
			UCSRC &= ~(1<<1);
			UCSRC |= (1<<2);
			break;
		}
		case USART_DATA_BITS_8:
		{
			USART->UCSRB &= ~(1<<2);
			UCSRC |= (3<<1);
			break;
		}
		
		default:
			break;
		
	}
	//-------------------------------------------------------------------
	//stop bits
	UCSRC |= (1<<7);
	UCSRC |= USART_config->Stop_Bits;
	
	//parity
	UCSRC |= (1<<7);
	UCSRC |= USART_config->Parity;
	
	//IRQ 
	if(USART_config->IRQ_EN != USART_IRQ_ENABLE_NONE){
		USART->UCSRB |= USART_config->IRQ_EN;
		EXTI_GLOBAL_Enable();
		switch(USART_config->IRQ_EN){
			
			case USART_IRQ_ENABLE_RX:
			{
				GP_IRQ_CALL[0] = USART_config->P_IRQ_CALL;
				break;
			}
			case USART_IRQ_ENABLE_UDR:
			{
				GP_IRQ_CALL[1] = USART_config->P_IRQ_CALL;
				break;
			}
			case USART_IRQ_ENABLE_TX:
			{
				GP_IRQ_CALL[2] = USART_config->P_IRQ_CALL;
				break;
			}
		}
	}
	
	//enable
	USART->UCSRB |= USART_config->Mode;
	
	//configure XCLK pin (PB0) in case of synch mode
	GPIO_PIN_CONFIG pinconfig;
	if(USART_config->Operating_Mode == USART_Operating_Mode_synch_Master){
		pinconfig.GPIO_Pin_Number = GPIO_PIN0;
		pinconfig.GPIO_Mode = GPIO_MODE_OUTPUT;
		MCAL_GPIO_Init(GPIOB, &pinconfig);
	}
	else if(USART_config->Operating_Mode == USART_Operating_Mode_synch_Slave){
		pinconfig.GPIO_Pin_Number = GPIO_PIN0;
		pinconfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
		MCAL_GPIO_Init(GPIOB, &pinconfig);
	}
	
}
void MCAL_USART_DeInit(void){
	USART->UCSRB = 0;
	USART->UBRRL = 0;
	UCSRC = 0b10000110;
	USART->UCSRA = 0b00100000;
}
void MCAL_USART_ReceiveData( char* RXBuffer , enum polling_mechanism polling_EN){
	
	if(polling_EN == Enable){
		while(!(USART->UCSRA & (1<<7)));
	}
	*RXBuffer = USART->UDR ;
}
void MCAL_USART_SendData( char data , enum polling_mechanism polling_EN){
	if(polling_EN == Enable){
		while(!(USART->UCSRA & (1<<5)));
	}
	USART->UDR = data;
}


void MCAL_USART_Send_String( char* TXBuffer){
	while (*TXBuffer != '\0') {
		MCAL_USART_SendData(*TXBuffer,Enable);
	    TXBuffer++;
	}
	//to indicate end
	MCAL_USART_SendData('\r',Enable);
}
void MCAL_USART_Receive_String( char* RXBuffer ){
	MCAL_USART_ReceiveData(RXBuffer,Enable);
	while (*RXBuffer != '\r') {
		RXBuffer++;
		MCAL_USART_ReceiveData(RXBuffer,Enable);
	}
	*RXBuffer = '\0';
}

//-------------------------------------------------ISR functions-----------------------------------------------

void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	
	GP_IRQ_CALL[0]();
}

void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{
	
	GP_IRQ_CALL[1]();
}

void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	
	GP_IRQ_CALL[2]();
}
