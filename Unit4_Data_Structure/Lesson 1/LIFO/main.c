#include <stdio.h>
#include "LIFO.h"

#define BUFFER_SIZE 5

int main()
{
	element_t item=0;
	Lifo_Buffer_t uartbuffer;
	element_t buffer[BUFFER_SIZE];
	if(LIFO_init(&uartbuffer,buffer,BUFFER_SIZE)==LIFO_no_error)
	{
		printf("===============pushing in LIFO================\n");
		for(element_t i=0;i<7;i++)
		{
			if(LIFO_push(&uartbuffer,i)==LIFO_no_error)
				printf("%d is pushed \n",i);
			else
				printf("%d can't be pushed \n",i);
		}

		printf("===============poping from LIFO===============\n");
		for(int i=0;i<7;i++)
		{
			if(LIFO_pop(&uartbuffer,&item)==LIFO_no_error)
				printf("%d is poped \n",item);
		}
	}
	else
	{
		printf("Error in intializtion");
	}


	return 0;
}