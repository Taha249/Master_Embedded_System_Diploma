/*
* Timer1_FPWM_PhaseCPWM.c
*
* Created: 10/29/2021 7:16:07 PM
* Author : user
*/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRD |= (1<<5);
	DDRC |= (1<<5)|(1<<6);
	TCCR1A = (1<<COM1A1)|(1<<WGM11);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);//N=64 - FPWM - NON Inverting
	ICR1 = 1000;
	OCR1A = 1000;
	while (1)
	{
		//PORTC |= (1<<5);
		//PORTC &=~ (1<<6);
		//_delay_ms(1000);
		//PORTC &=~ (1<<6)|(1<<5);//MOTOR OFF
		//_delay_ms(1000);
		OCR1A = 1000;
		PORTC |= (1<<6);
		PORTC &=~ (1<<5);
		_delay_ms(1000);
		OCR1A = 500;
		_delay_ms(1000);
	}
}

