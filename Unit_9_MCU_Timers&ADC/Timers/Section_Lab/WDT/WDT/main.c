/*
 * WDT.c
 *
 * Created: 2/26/2024 4:42:46 AM
 * Author : Taha
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void WDT_ON();
void WDT_OFF();

int main(void)
{
	WDT_ON();
	DDRC |= (1<<7);
	PORTC |= (1<<7);
	_delay_ms(500);
	PORTC &=~ (1<<7);
	while (1)
	{
	}
}

void WDT_ON(){
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);//enable & reset after 2.1s
}

void WDT_OFF(){
	WDTCR |= (1<<WDE)|(1<<WDTOE);
	WDTCR = 0x00;
}
