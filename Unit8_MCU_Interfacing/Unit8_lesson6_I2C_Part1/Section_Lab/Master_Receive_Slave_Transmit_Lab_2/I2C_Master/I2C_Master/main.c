/*
 * I2C_Master.c
 *
 * Created: 1/6/2024 1:50:41 AM
 * Author : Taha
 */ 

#include <avr/io.h>
#include "I2C.h"

int main(void)
{
	unsigned char ch;
	DDRA=0xFF;                                   
	I2C_INIT(0x48);                          
	while (1)
	{
		_delay_ms(250);
		I2C_START();                      
		I2C_WRITE(0b11010000+1);          
		ch=I2C_READ(0);                  
		I2C_STOP();
		PORTA=ch;
	}
	return 0;
}
