#include "I2C _Driver.h"


#define prescaler 1 //1 4 16 64

void I2C_Init(unsigned long SCL_Clock){
	//TWBR selects the division factor for the bit rate generator.
	//The bit rate generator is a frequency divider which generates the SCL clock frequency in the Master modes
	TWBR = (unsigned char) (((F_CPU/SCL_Clock)-16)/(2*prescaler));
	
	//Bits 1:0 – TWPS: TWI Prescaler Bits
	//These bits can be read and written, and control the bit rate prescaler
	if(prescaler == 0){
		TWSR = 0;
	}
	else if(prescaler == 4){
		TWSR = 1;
	}
	else if(prescaler == 16){
		TWSR = 2;
	}
	else if(prescaler == 64){
		TWSR = 3;
	}
	
	
	
	
}
void I2C_Start(void){
	
	//The TWEN bit enables TWI operation and activates the TWI interface. When TWEN is written to one, the TWI
	//takes control over the I/O pins connected to the SCL and SDA pins
	
	
	//The TWINT Flag must be cleared by software by writing a logic one to it. Note that this flag is not automatically
	//cleared by hardware when executing the interrupt routine. Also note that clearing this flag starts the operation of
	//the TWI, so all accesses to the TWI Address Register (TWAR), TWI Status Register (TWSR),
	//and TWI Data Register (TWDR) must be complete before clearing this flag
	
	
	//The application writes the TWSTA bit to one when it desires to become a master on the Two-wire Serial Bus. The
	//TWI hardware checks if the bus is available, and generates a START condition on the bus if it is free
	
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	//wait for this bit to be set by hardware
	while(!(TWCR & (1<<TWINT)));
	
	while(TWSR != 0x08);
	
}


void I2C_Write(unsigned char cByte){
	
	TWDR = cByte;
	
	TWCR = (1<<TWINT)|(1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));
}


void I2C_Stop(){
	//Writing the TWSTO bit to one in Master mode will generate a STOP condition on the Two-wire Serial Bus. When
	//the STOP condition is executed on the bus, the TWSTO bit is cleared automatically
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}