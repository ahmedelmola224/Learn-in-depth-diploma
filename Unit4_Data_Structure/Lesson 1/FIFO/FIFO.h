#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdint.h>


#define element_t  uint8_t

typedef struct 
{
	element_t * head;
	element_t * tail;
	element_t *base;
	uint32_t length;
	uint32_t count;
}Fifo_Buffer_t;

typedef enum 
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}Fifo_Buffer_Status;


Fifo_Buffer_Status FIFO_init(Fifo_Buffer_t* fBuf,element_t* arr,unsigned int length);
Fifo_Buffer_Status FIFO_enqueue(Fifo_Buffer_t* fBuf,element_t item);
Fifo_Buffer_Status FIFO_dequeue(Fifo_Buffer_t* fBuf,element_t *item);
Fifo_Buffer_Status FIFO_isfull(Fifo_Buffer_t* fBuf);
void FIFO_print(Fifo_Buffer_t* fBuf);

#endif