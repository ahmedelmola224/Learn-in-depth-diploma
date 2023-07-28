#include "FIFO.h"

Fifo_Buffer_Status FIFO_init(Fifo_Buffer_t* fBuf,element_t* arr,unsigned int length)
{
	if(arr==NULL || fBuf==NULL)
		return FIFO_null;

	fBuf->length=length;
	fBuf->count=0;
	fBuf->base=arr;
	fBuf->head=arr;
	fBuf->tail=arr;
	return FIFO_no_error;
}

Fifo_Buffer_Status FIFO_enqueue(Fifo_Buffer_t* fBuf,element_t item)
{
	if(fBuf==NULL||fBuf->head==NULL||fBuf->base==NULL||fBuf->tail==NULL)
		return FIFO_null;

	if(FIFO_isfull(fBuf))
		return FIFO_full;

	*(fBuf->head)=item;
	 (fBuf->count)++;

	if(fBuf->head==(fBuf->base+((fBuf->length) *sizeof(element_t))-1))
		fBuf->head=fBuf->base;
	else
		(fBuf->head)++;

	return FIFO_no_error;

}

Fifo_Buffer_Status FIFO_dequeue(Fifo_Buffer_t* fBuf,element_t *item)
{
	if(fBuf==NULL||fBuf->head==NULL||fBuf->base==NULL||fBuf->tail==NULL)
		return FIFO_null;

	if((fBuf->count)==0)
		return FIFO_empty;

	*item=*(fBuf->tail);
	(fBuf->count)--;

	if(fBuf->tail==(fBuf->base+((sizeof(element_t)* fBuf->length))-1))
		fBuf->tail=fBuf->base;
	else
		fBuf->tail++;

	return FIFO_no_error;

}

Fifo_Buffer_Status FIFO_isfull(Fifo_Buffer_t* fBuf)
{
	if(fBuf==NULL||fBuf->head==NULL||fBuf->base==NULL||fBuf->tail==NULL)
		return FIFO_null;

	if(fBuf->count==fBuf->length)
	{
		printf("FIFO FULL");
		return FIFO_full;
	}
	return FIFO_no_error;
}

void FIFO_print(Fifo_Buffer_t* fBuf)
{
	element_t *temp=fBuf->tail;
	printf("===========print FIFO=============\n");
	for(int i=0;i<fBuf->count;i++)
	{
		printf("\t %X \n",*temp);
		if(temp==(fBuf->base+((sizeof(element_t)* fBuf->length))-1))
			temp=fBuf->base;
		else
			temp++;

	}
	printf("========================\n");
}