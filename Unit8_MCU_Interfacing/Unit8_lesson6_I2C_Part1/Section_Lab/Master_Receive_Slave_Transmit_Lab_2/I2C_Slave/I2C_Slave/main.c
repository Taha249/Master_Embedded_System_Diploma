/*
 * I2C_Slave.c
 *
 * Created: 1/6/2024 1:54:23 AM
 * Author : Taha
 */ 

#include <avr/io.h>
#include "I2C.h"

int main(void)
{
	unsigned char ch=0;
	I2C_Set_Address(0b11010000);    
	while (1)
	{
		I2C_Read(1);            
		I2C_Write(ch++);         
	}
	return 0;
}

