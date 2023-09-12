


#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_

#include "ATMEGA32.h"

typedef struct {
	
	uint8_t Mode; 	                //specifies the USART (TX/RX) to be configured .
											//this parameter must be set based on  @ ref  USART_MODE_Define
	
	uint8_t Clock_Polarity; 	    //specifies the USART Transmitted Data Changed (Transmitted as Rising XCK Edge and Received Falling XCK Edge ) or (Transmitted as Falling XCK Edge and Received Rising XCK Edge ) .
											//this parameter must be set based on  @ ref  USART_Clock_Polarity_Define
	
	uint8_t Operating_Mode; 	           //this parameter must be set based on  @ ref  USART_OPERATING_MODE_Define 
	

	uint8_t Data_Bits;	           //specifies the number of data bit (5 --> 9 ) .
											//this parameter must be set based on  @ ref USART_DATA_BITS_Define

	uint8_t Stop_Bits;	           //specifies the number of stop bit ( 0.5 or 1 or 1.5 or 2 ) .
											//this parameter must be set based on  @ ref  USART_STOP_BITS_Define

	uint16_t Baud_Rate;	           //specifies the baud rate  .
											//this parameter must be set based on  @ ref  USART_BAUD_RATE_Define

	uint8_t Parity;	              //specifies the parity disable or enable (odd or even ) .
											//this parameter must be set based on  @ ref  USART_PARITY_Define

	uint8_t IRQ_EN;	              //specifies the interrupt (disable or enable )  .
											//this parameter must be set based on  @ ref  USART_IRQ_ENABLE_Define

	void (*P_IRQ_CALL)(void);	// set the function which will be call at IRQ happen

	
}USART_CONFIG;


//--------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------

//@ref  USART_MODE_Define (in UCSRB register)
#define USART_MODE_TX			(uint8_t)(1<<3)
#define USART_MODE_RX			(uint8_t)(1<<4)
#define USART_MODE_TX_RX		(uint8_t)(1<<3 | 1<<4)


//@ref  USART_Clock_Polarity_Define (in UCSRC register)
#define USART_Clock_Transmit_Rising      (uint8_t)(0)
#define USART_Clock_Transmit_Falling     (uint8_t)(1<<0)

//@ref  USART_Operating_MODE_Define 
#define USART_Operating_Mode_Asynch_Double_Speed		0
#define USART_Operating_Mode_Asynch_Normal			    1
#define USART_Operating_Mode_synch_Master				2
#define USART_Operating_Mode_synch_Slave				3


//@ref USART_DATA_BITS_Define
#define USART_DATA_BITS_5                        0
#define USART_DATA_BITS_6                        1
#define USART_DATA_BITS_7                        2
#define USART_DATA_BITS_8                        3



//@ref  USART_STOP_BITS_Define (in UCSRC register)
#define USART_STOP_BITS_1          (uint8_t)(0)
#define USART_STOP_BITS_2          (uint8_t)(1<<3)


//@ref  USART_BAUD_RATE_Define
#define USART_BAUD_RATE_2400						2400
#define USART_BAUD_RATE_4800						4800
#define USART_BAUD_RATE_9600						9600
#define USART_BAUD_RATE_14400						14400
#define USART_BAUD_RATE_19200						19200
#define USART_BAUD_RATE_28800						28800
#define USART_BAUD_RATE_38400						38400
#define USART_BAUD_RATE_57600						57600
#define USART_BAUD_RATE_76800						76800
#define USART_BAUD_RATE_115200						115200


//@ref  USART_PARITY_Define
#define USART_PARITY_NONE           (uint8_t)(0)
#define USART_PARITY_EVEN           (uint8_t)(2<<4)
#define USART_PARITY_ODD            (uint8_t)(3<<4)


//@ref  USART_IRQ_ENABLE_Define
#define USART_IRQ_ENABLE_NONE			    (uint8_t)(0)
#define USART_IRQ_ENABLE_RX					(uint8_t)(1<<7)
#define USART_IRQ_ENABLE_UDR				(uint8_t)(1<<5)	
#define USART_IRQ_ENABLE_TX					(uint8_t)(1<<6)	   
	   

enum polling_mechanism
{
	Enable,
	Disable
};

/*
 * ===============================================
 * APIs Supported by "MCAL USART DRIVER"
 * ===============================================
 */

void MCAL_USART_Init(USART_CONFIG* USART_config );
void MCAL_USART_DeInit(void);
void MCAL_USART_ReceiveData( char* RXBuffer , enum polling_mechanism polling_EN);
void MCAL_USART_SendData( char data , enum polling_mechanism polling_EN);
void MCAL_USART_Send_String(char* TXBuffer);
void MCAL_USART_Receive_String( char* RXBuffer );
#endif /* USART_DRIVER_H_ */