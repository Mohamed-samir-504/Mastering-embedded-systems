

typedef struct LIFO{
    unsigned int length;
    unsigned int count;
    unsigned int* Base;
    unsigned int* Head;
}LIFO_BUFF_t;

typedef enum {

	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFIO_EMPTY,
	LIFO_NULL
}LIFO_Status;

LIFO_Status LIFO_init(LIFO_BUFF_t *lifo_buff ,unsigned int *Buff,unsigned int length);
LIFO_Status LIFO_add_item(LIFO_BUFF_t *lifo_buff ,unsigned int item);
LIFO_Status LIFO_get_item(LIFO_BUFF_t *lifo_buff ,unsigned int *item);

