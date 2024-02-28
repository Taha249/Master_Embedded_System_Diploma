/*
* Timer0_Delay_E25.c
*
* Created: 11/19/2021 2:45:48 PM
* Author : Taha
*/

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned long OVF_Count = 0;

int main(void)
{
	DDRC |= (1<<7);
	sei();
	TCCR0 &=~ (1<<WGM00)|(1<<WGM01);//normal mode
	TCCR0 |= (1<<CS00)|(1<<CS01);//N = 64 (Prescaler)
	TIMSK |= (1<<TOIE0)|(1<<OCIE0);//enable overflow and compare match interrupts
	//TCNT0 = 111;
	OCR0 = 143;
	while (1)
	{
	}
}
/*
ISR(TIMER0_OVF_vect){
OVF_Count++;
if( OVF_Count == 977){
PORTC ^= (1<<7);
OVF_Count = 0;
TCNT0 = 111;
}
}
*/

ISR(TIMER0_OVF_vect){
	OVF_Count++;
}
ISR(TIMER0_COMP_vect){
	if( OVF_Count == 976){
		PORTC ^= (1<<7);
		OVF_Count = 0;
		TCNT0 = 0;
	}
}
