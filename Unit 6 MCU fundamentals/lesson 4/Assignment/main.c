
#define F_CPU 1000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>


#define IO_BASE   0x20
#define PORTD    *(volatile unsigned int *) (IO_BASE + 0x12)
#define DDRD     *(volatile unsigned int *) (IO_BASE + 0x11)
#define MCUCR    *(volatile unsigned int *) (IO_BASE + 0x35)
#define MCUCSR   *(volatile unsigned int *) (IO_BASE + 0x34)
#define GICR     *(volatile unsigned int *) (IO_BASE + 0x3B)

int main(void)
{

	//Enable global interrupt
	sei();

	//Enable PORTD pins s output
	DDRD |= (0b111<<5);

	//Make INT0 as any logical change
	//Make INT1 as rising edge
	MCUCR |= (0b1101<<0);

	//Make INT2 as falling edge
	MCUCSR &= ~(1<<6);

	//Enable INT0, INT1 and INT2
	GICR != (0b111<<5);
	
    while(1)
    {

    	//turn off all leds
		PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ;
		_delay_ms(1000);
    }
}

ISR(INT0_vect)
{
	
	PORTD |= (1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	
	PORTD |= (1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	
	PORTD |= (1<<7) ;
	_delay_ms(1000);
}




