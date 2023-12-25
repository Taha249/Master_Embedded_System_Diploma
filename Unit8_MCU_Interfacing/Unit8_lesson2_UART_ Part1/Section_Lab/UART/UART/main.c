/*
 * UART.c
 *
 * Created: 12/25/2023 3:48:07 PM
 * Author : Taha
 */ 

#include <avr/io.h>
#include "UART.h"
#include "lcd.h"

uint8_t x=0;
int main(void)
{
	LCD_INIT();
	Uart_Init();
	LCD_GOTO_XY(0,0);
	LCD_WRITE_STRING("Eng.Taha");
	Uart_Transmit('T');
	Uart_Transmit('R');
	Uart_Transmit('L');
	while (1)
	{
		
		LCD_GOTO_XY(1,0);
		x= Uart_Receive();
		LCD_WRITE_CHAR(x);
		}
}

