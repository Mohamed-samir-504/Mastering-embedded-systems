#include "UART.h"

#define UART0_DR *((volatile unsigned int*)((unsigned int *)0x101f1000))

void UART_sendString(unsigned char* Tx_string){

    while(*Tx_string != '\0'){
        
        UART0_DR = (unsigned int)(*Tx_string);
        Tx_string++;
    }
}