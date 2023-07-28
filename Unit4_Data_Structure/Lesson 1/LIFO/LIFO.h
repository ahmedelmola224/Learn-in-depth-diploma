#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdint.h>


#define element_t  uint8_t

typedef struct 
{
	element_t * head;
	element_t *base;
	uint32_t length;
	uint32_t count;
}Lifo_Buffer_t;

typedef enum 
{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_null
}Lifo_Buffer_Status;

Lifo_Buffer_Status LIFO_init(Lifo_Buffer_t* lBuf,element_t* arr,unsigned int length);
Lifo_Buffer_Status LIFO_push(Lifo_Buffer_t* lBuf,element_t item);
Lifo_Buffer_Status LIFO_pop(Lifo_Buffer_t* lBuf,element_t *item);


 #endif