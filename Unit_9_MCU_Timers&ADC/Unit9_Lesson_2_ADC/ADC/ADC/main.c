/*
 * ADC.c
 *
 * Created: 3/2/2024 1:48:06 PM
 * Author : Taha
 */ 

#include <stdlib.h>
#include "Inc/ADC.h"
#include <util/delay.h>

int main(void)
{
	DIO_Init();
	LCD_INIT();
	ADC_Init();
	unsigned short temp = 0;
	char string[20];
	while (1)
	{
		temp = ADC_Read(1);
		temp = temp/4;
		itoa(temp,string,10);
		LCD_WRITE_STRING(string);
		_delay_ms(200);
		LCD_WRITE_COMMAND(0x01);
	}
}


