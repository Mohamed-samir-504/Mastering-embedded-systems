
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7 

void SPI_MasterInit(void)
{
	//Set MOSI, SCK and SS output, all others input 
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	// Set MISO input 
	DDRB &= ~(1<<MISO);
	//Enable SPI, Master, set clock rate fck/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
unsigned char SPI_MasterTransmit(unsigned char data)
{
	//Start transmission 
	SPDR = data;
	// Wait for transmission complete 
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}


int main(void)
{
   
	unsigned char ch = 0;
	//for 7 segment
	DDRA = 0xFF;
	
	SPI_MasterInit();
	_delay_ms(1000);
	//PORTA = SPI_MasterTransmit(1);
	for (ch = 0; ch <= 255; ch++)
	{
		_delay_ms(1000);
		PORTA = SPI_MasterTransmit(ch);
	}
}

