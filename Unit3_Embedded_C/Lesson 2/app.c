#include "uart.h"

unsigned char str_buffer[100]="learn-in-depth-<Ahmed Essam>";
 unsigned char const str_buffer2[100]="mohamed";
void main(void)
{
	Uart_Send_string(str_buffer);
	return ;
} 