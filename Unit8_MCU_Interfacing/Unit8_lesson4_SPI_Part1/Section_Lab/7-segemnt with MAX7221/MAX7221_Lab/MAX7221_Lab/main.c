/*
 * MAX7221_Lab.c
 *
 * Created: 12/30/2023 11:49:09 PM
 * Author : Taha
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SPI_M/M_SPI.h"

void execute(unsigned char cmd, unsigned char data)
{
	PORTB &= ~(1 << SS);
	SPDR = cmd;
	while (!(SPSR & (1 << SPIF)));
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
	PORTB |= (1 << SS);
}


int main(void)
{
    /* Replace with your application code */
    unsigned char counter = 0;
    unsigned char index_display;
    SPI_InitOptions MyState = {Master,};
    SPI_Init(MyState);
    Slave_Enable();
    execute(0x09, 0xFF);
    execute(0x0A, 0xFF);
    execute(0x0B, 0xF7);
    execute(0x0C, 0x01);
    while (1)
    {
	    for (index_display = 1; index_display < 9; index_display++)
	    execute(index_display, counter++);
	    _delay_ms(1000);
    }
}

