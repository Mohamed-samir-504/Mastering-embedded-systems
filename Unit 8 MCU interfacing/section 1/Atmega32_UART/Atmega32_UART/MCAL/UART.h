


#ifndef UART_H_
#define UART_H_

#include "Util.h"
#include <stdint.h>
#include <avr/io.h>


//#define Even_Parity       
#define two_stop_bit     
#define frame_size 8   

void UART_init();
void UART_SendChar(char data);
char UART_ReceiveChar();
void UART_SendString(char* str);
void UART_ReceiveString(char *Buffer);




#endif /* UART_H_ */