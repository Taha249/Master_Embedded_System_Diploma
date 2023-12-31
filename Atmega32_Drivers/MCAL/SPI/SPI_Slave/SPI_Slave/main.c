/*
 * SPI_Slave.c
 *
 * Created: 12/30/2023 11:28:01 PM
 * Author : Taha
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "S_SPI.h"


int main(void)
{
    /* Replace with your application code */
    unsigned char ch = 255;
    DDRA = 0xFF;
    SPI_Init('S');
    for (ch = 255; ch >= 0; ch--)
    {
	    PORTA = SPI_TxRx(ch);
    }
}

