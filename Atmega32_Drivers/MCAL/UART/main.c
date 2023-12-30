/*
* UART_E25.c
*
* Created: 11/27/2021 3:49:34 PM
* Author : user
*/

#include <avr/io.h>
#include "UART.h"


int main(void)
{
	DDRC |= (1<<7);
	Uart_Init();
	Uart_TransmitString("Eng.Taha");
	while (1)
	{
		if(Uart_Receive() == '1'){
			PORTC ^= (1<<7);
		}
	}
}

