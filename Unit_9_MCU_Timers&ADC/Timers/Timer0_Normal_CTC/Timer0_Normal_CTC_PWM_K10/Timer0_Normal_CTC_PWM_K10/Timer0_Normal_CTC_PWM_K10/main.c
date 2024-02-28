/*
* Timer0_Normal_CTC_PWM_K10.c
*
* Created: 10/23/2021 9:13:06 PM
* Author : user
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRB |= (1<<3);
	//TCCR0 = (1<<COM00)|(1<<CS00)|(1<<CS01);//Normal mode & TIMER CLK = CPU_CLK / 64 & TOGGLE ON COMPARE MATCH
	TCCR0 = (1<<WGM01)|(1<<COM00)|(1<<CS00)|(1<<CS01);//CTC & TIMER CLK = CPU_CLK / 64 & TOGGLE ON COMPARE MATCH
	
	while (1)
	{
		OCR0 = 50;
		_delay_ms(500);
		OCR0 = 240;
		_delay_ms(500);
	}
}

