#include "LIFO.h"


Lifo_Buffer_Status LIFO_init(Lifo_Buffer_t* lBuf,element_t* arr,unsigned int length)
{
	if(arr==NULL || lBuf==NULL)
		return LIFO_null;
	lBuf->length=length;
	lBuf->count=0;
	lBuf->base=arr;
	lBuf->head=arr;
	return LIFO_no_error;
}

Lifo_Buffer_Status LIFO_push(Lifo_Buffer_t* lBuf,element_t item)
{
	if( lBuf==NULL||lBuf->head==NULL||lBuf->base==NULL)
		return LIFO_null;
	if(lBuf->count==lBuf->length)
		return LIFO_full;

	*(lBuf->head)=item;
	(lBuf->head)++;
	(lBuf->count)++;
	return LIFO_no_error;
}


Lifo_Buffer_Status LIFO_pop(Lifo_Buffer_t* lBuf,element_t *item)
{
	if( lBuf==NULL||lBuf->head==NULL||lBuf->base==NULL)
		return LIFO_null;
	if(lBuf->count==0)
		return LIFO_empty;

	(lBuf->head)--;
	*item = *(lBuf->head);
	(lBuf->count)--;
	return LIFO_no_error;
}


