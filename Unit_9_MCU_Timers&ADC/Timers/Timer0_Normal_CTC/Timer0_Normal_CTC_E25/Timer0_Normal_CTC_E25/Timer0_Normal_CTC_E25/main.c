/*
* Timer0_Delay_E25.c
*
* Created: 11/19/2021 2:45:48 PM
* Author : user
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

volatile unsigned short arr[2] = {50,200};
volatile unsigned short arr_Flag = 0;
int main(void)
{
	sei();
	DDRB |= (1<<3);//OC0 PIN  OUTPUT
	TCCR0 |= (1<<WGM01);//CTC mode
	TCCR0 &=~ (1<<WGM00);
	TCCR0 |= (1<<CS00)|(1<<CS01)|(1<<COM00);//N = 64 (Prescaler) & Toggle on compare match
	TIMSK |= (1<<OCIE0);
	OCR0 = arr[0];
	while (1)
	{

	}
}

ISR(TIMER0_COMP_vect){
	switch(arr_Flag){
		case 0:
		arr_Flag = 1;
		OCR0 = arr[arr_Flag];
		break;
		case 1:
		arr_Flag = 0;
		OCR0 = arr[arr_Flag];
		break;
	}
}