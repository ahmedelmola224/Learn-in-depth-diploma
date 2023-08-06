/*
 * FIFO.h
 *
 *  Created on: Aug 6
 *  Author: Ahmed Essam
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdint.h>
#include "STD.h"

#define DPRINTF(...) {fflush(stdout); \
					  fflush(stdin); \
					  printf(__VA_ARGS__); \
					  fflush(stdout); \
					  fflush(stdin);}
					  


#define element_t  sinfo


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
	FIFO_error,
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
Fifo_Buffer_Status FIFO_get_element(Fifo_Buffer_t* fBuf,element_t* element,int element_count);
Fifo_Buffer_Status FIFO_get_count(Fifo_Buffer_t* fBuf,unsigned int *count);
Fifo_Buffer_Status FIFO_delete_nth_element(Fifo_Buffer_t* fBuf,unsigned int n);

#endif