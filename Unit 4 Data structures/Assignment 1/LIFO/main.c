#include "LIFO.h"
#include "stdio.h"
#include "stdlib.h"

unsigned int Buffer1[5];

void main()
{

    int temp = 0;

    LIFO_BUFF_t UART_BUFF, I2C_BUFF;

    LIFO_init(&UART_BUFF, Buffer1, 5);

    unsigned int *Buffer2 = (unsigned int *)malloc(5 * sizeof(unsigned int));

    LIFO_init(&I2C_BUFF, Buffer2, 5);

    for (int i = 0; i < 5; i++)
    {
        if (LIFO_add_item(&UART_BUFF, i) == LIFO_NO_ERROR)
            printf("UART_LIFO add : %d \n", i);
    }

    for (int i = 0; i < 5; i++)
    {
        if (LIFO_get_item(&UART_BUFF, &temp) == LIFO_NO_ERROR)
            printf("UART_LIFO get : %d \n", temp);
    }

    

}