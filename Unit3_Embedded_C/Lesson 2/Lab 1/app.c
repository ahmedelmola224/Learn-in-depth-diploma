#include "uart.h"

unsigned char str_buffer[100]="learn-in-depth-<Ahmed Essam>";
void main(void)
{
	Uart_Send_string(str_buffer);
	return ;
} 