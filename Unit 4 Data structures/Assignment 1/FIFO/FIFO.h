

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"


#define elementType unsigned char




typedef struct FIFO{

    unsigned int length;
    unsigned int count;
    elementType* Base;
    elementType* Head;
    elementType* Tail;

}FIFO_BUFF_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,
}FIFO_Status;


FIFO_Status FIFO_Init(FIFO_BUFF_t *fifo,elementType *buff,unsigned int length );
FIFO_Status Enqueue(FIFO_BUFF_t *fifo,elementType item);
FIFO_Status Dequeue(FIFO_BUFF_t *fifo,elementType *item);
FIFO_Status FIFO_ISFULL(FIFO_BUFF_t *fifo);
void FIFO_print(FIFO_BUFF_t *fifo);

#endif /* FIFO_H_ */
