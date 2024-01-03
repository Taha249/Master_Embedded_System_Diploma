/*
 * SPI_Master.c
 *
 * Created: 12/30/2023 11:07:27 PM
 * Author : Taha
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "M_SPI.h"


int main(void)
{
    /* Replace with your application code */
    unsigned char ch = 0;
    DDRA = 0xFF;
	SPI_InitOptions MyState = {Master,};
    SPI_Init(MyState);
	Slave_Enable();
    for (ch = 0; ch <= 255; ch++)
    {
	    _delay_ms(1000);
	    PORTA = SPI_TxRx(ch);
    }
}

