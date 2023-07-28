#include <stdio.h>
#include "FIFO.h"

#define BUFFER_SIZE 5

int main()
{
	Fifo_Buffer_t uartfifo;
	element_t arr[BUFFER_SIZE];
	unsigned char i=0,temp=0;
	if(FIFO_init(&uartfifo,arr,BUFFER_SIZE)==FIFO_no_error)
	{
		for(i=0;i<7;i++)
		{
			printf("Fifo Enqueue %X \n",i);
			if(FIFO_enqueue(&uartfifo,i)==FIFO_no_error)
				printf("FIFO ENQUEUE(%X)---------DONE \n",i);
			else
				printf("FIFO ENQUEUE(%X)---------failed \n",i);
		}
		FIFO_print(&uartfifo);
		FIFO_dequeue(&uartfifo,&temp);
		printf("FIFO dequeue Data=%X  \n",temp);
		FIFO_dequeue(&uartfifo,&temp);
		printf("FIFO dequeue Data=%X  \n",temp);
		for(i=6;i<8;i++)
		{
			printf("Fifo Enqueue %X \n",i);
			if(FIFO_enqueue(&uartfifo,i)==FIFO_no_error)
				printf("FIFO ENQUEUE(%X)---------DONE \n",i);
			else
				printf("FIFO ENQUEUE(%X)---------failed \n",i);
		}
		FIFO_print(&uartfifo);

	}

}