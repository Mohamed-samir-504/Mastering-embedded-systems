#include "LIFO.h"
#include "stdio.h"

LIFO_Status LIFO_add_item(LIFO_BUFF_t * lifo_buff,unsigned int item)
{
	
	if (!lifo_buff->Base || !lifo_buff->Head)
		return LIFO_NULL;

	
	if(lifo_buff->count==lifo_buff->length)
		return LIFO_FULL;

	*(lifo_buff->Head)=item;
	lifo_buff->Head++;
	lifo_buff->count++;

	return LIFO_NO_ERROR;


}

LIFO_Status LIFO_get_item(LIFO_BUFF_t *lifo_buff,unsigned int *item)
{

	
	if (!lifo_buff->Base || !lifo_buff->Head)
		return LIFO_NULL;

	
	if(lifo_buff->count==0)
		return LIFIO_EMPTY;

	lifo_buff->Head--;
	*item=*(lifo_buff->Head);
	lifo_buff->count--;


	return LIFO_NO_ERROR;


}

LIFO_Status LIFO_init(LIFO_BUFF_t *lifo_buff,unsigned int* Buff,unsigned int length)
{

	if (Buff == NULL)
		return LIFO_NULL;

	lifo_buff->Base=Buff;
	lifo_buff->Head=Buff;
	lifo_buff->length=length;
	lifo_buff->count=0;

	return LIFO_NO_ERROR;
}
