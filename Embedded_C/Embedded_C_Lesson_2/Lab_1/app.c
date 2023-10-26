//@ learn-in-depth
// Taha Mohamed

#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:<Taha>";
void main(void)
{
	Uart_send_string(string_buffer);
}