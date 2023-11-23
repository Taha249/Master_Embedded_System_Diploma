/*
 * Unit6_Lesson4_Lab3.c
 *
 * Created: 11/23/2023 5:37:27 PM
 * Author : TAHA Mohamed
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
typedef volatile unsigned char vc8_t ;

#define Base 0x20

// INTR.
#define SREG *(vc8_t*)(Base + 0x3F)
#define MCUCR *(vc8_t*)(Base + 0x35)
#define GICR *(vc8_t*)(Base + 0x3B)


void INT_init ()
{
	//Make INT 0 (Any logic Change 01)
	MCUCR |= 1<<0 ;
	//Make INT 1 (The rising edge 11)
	MCUCR |= 0b11<<2 ;
	// Enable All EXTI
	GICR |= 0b111<<5 ;
	//Global Interrupt Enable
	SREG |= 1<<7 ;
}

// GPIO
#define PORTA *(vc8_t*)(Base + 0x1B)
#define DDRA *(vc8_t*)(Base + 0x1A)
#define PORTB *(vc8_t*)(Base + 0x18)
#define DDRB *(vc8_t*)(Base + 0x17)
#define PORTD *(vc8_t*)(Base + 0x12)
#define DDRD *(vc8_t*)(Base + 0x11)


void GPIO_init ()
{
	DDRA |= 0b111<<0 ;
}
int main ()
{
	INT_init ();
	GPIO_init ();
	while (1){
		PORTA = 0x0 ;
	}
	return 0 ;
}

// ISR INT0,1,2
ISR(INT0_vect)
{
	PORTA |= (1<<0) ;
	_delay_ms(100);
}
ISR(INT1_vect)
{
	PORTA |= (1<<1) ;
	_delay_ms(100);
}
ISR(INT2_vect)
{
	PORTA |= (1<<2) ;
	_delay_ms(100);
}