

#include "FIFO.h"
#include "stdio.h"

#define width 5

elementType Buffer[width];

void main(){

	FIFO_BUFF_t FIFO_UART;
	elementType temp;
	if(FIFO_Init(&FIFO_UART,Buffer,5) == FIFO_NO_ERROR){
		printf("FIFO init is done\n");
	}


	for (elementType i=0;i<7;i++)
	{

		printf("FIFO Enqueue (%x) \n",i);

		if(Enqueue(&FIFO_UART, i)==FIFO_NO_ERROR){
			printf("FIFO Enqueue (%x) ------DONE\n",i);
		}

		else{
			printf("FIFO Enqueue (%x)-------Failed \n",i);
		}
	}

	FIFO_print(&FIFO_UART);

	if(Dequeue(&FIFO_UART,&temp) == FIFO_NO_ERROR){
			printf("FIFO dequeue %x----- done\n",temp);
		}
	if(Dequeue(&FIFO_UART,&temp) == FIFO_NO_ERROR){
				printf("FIFO dequeue %x----- done\n",temp);
			}

	FIFO_print(&FIFO_UART);


}
