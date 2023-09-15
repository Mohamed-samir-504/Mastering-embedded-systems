#include "I2C _Driver.h"


void I2C_Set_Address(unsigned char addr){
	TWAR = addr;
}
unsigned char I2C_Read(unsigned char ack){
	
	unsigned char x = 0;
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	while(!(TWCR & (1<<TWINT)));
	while(TWSR != 0x60)x=TWSR;
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	while(!(TWCR & (1<<TWINT)));
	while(TWSR != 0x80)x=TWSR;
	return TWDR;
	
}