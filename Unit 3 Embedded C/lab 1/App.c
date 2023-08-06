#include "UART.h"

unsigned char string_buffer[100] = "learn-in-depth:Mohamed";

void main(void){

	UART_sendString(&string_buffer[0]);
}