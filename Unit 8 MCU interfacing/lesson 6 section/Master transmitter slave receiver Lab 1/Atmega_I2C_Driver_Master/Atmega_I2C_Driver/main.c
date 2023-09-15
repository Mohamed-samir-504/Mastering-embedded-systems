

#include <avr/io.h>
#include <util/delay.h>
#include "I2C _Driver.h"

int main(void)
{
	unsigned char ch = 0;
	I2C_Init(0x48);
	
    
    while (1) 
    {
		_delay_ms(500);
		
		I2C_Start();    //transmit start condition
		
		I2C_Write(0b11010000+0);   //transmit slave address + W(0)
		
		while(TWSR != 0x18);      //slave address + W(0) has been transmitted and ACK has been received
		
		I2C_Write(ch++);   //transmit data
		
		while(TWSR != 0x28);   //data has been transmitted and ACK has been received
		
		I2C_Stop();
    }
}

