#include "Fifo.h"
#include "stdio.h"



FIFO_Status FIFO_Init(FIFO_BUFF_t *fifo,elementType *buff,unsigned int length )
{
	if(buff == NULL ) return FIFO_NULL;

	fifo->Head=buff;
	fifo->Base=buff;
	fifo->Tail=buff;
	fifo->length=length;
	fifo->count=0;

	return FIFO_NO_ERROR;

}

FIFO_Status FIFO_ISFULL(FIFO_BUFF_t *fifo)

{
	if(!fifo->Head || !fifo->Base ||!fifo->Tail)
			return FIFO_NULL;

	if (fifo->count == fifo->length)
	{
		printf("FIFO IS FULL\n");
		return FIFO_FULL;
	}

	return FIFO_NO_ERROR;

}

FIFO_Status Enqueue(FIFO_BUFF_t *fifo,elementType item)
{
	if(!fifo->Base || !fifo->Head || !fifo->Tail ) return FIFO_NULL;

	if(FIFO_ISFULL(fifo) == FIFO_FULL) return FIFO_FULL;

	*(fifo->Head)=item;
	fifo->count++;

	if(fifo->Head == (fifo->Base)+(fifo->length)*sizeof(elementType))
		fifo->Head=fifo->Base;
	else
		fifo->Head++;

	return FIFO_NO_ERROR;

}

FIFO_Status Dequeue(FIFO_BUFF_t *fifo,elementType *item)
{
	if(!fifo->Base || !fifo->Head || !fifo->Tail ) return FIFO_NULL;

	if(fifo->count == 0) return FIFO_EMPTY;

	*item = *(fifo->Tail);
	fifo->count--;

	if(fifo->Tail == (fifo->Base)+(fifo->length)*sizeof(elementType))
			fifo->Tail=fifo->Base;

	else
		fifo->Tail++;


	return FIFO_NO_ERROR;

}


void FIFO_print(FIFO_BUFF_t *fifo)

{

	elementType *temp;
	if (fifo->count==0)
	{
		printf("FIFO IS Empty\n");

	}
	else{
		temp=fifo->Tail;
			printf("===================FIFO Print==================\n");
			for(int i=0;i<fifo->count;i++)
			{
				printf("\t %x \n",*temp);
				temp++;
			}
	}

}



