/*
 * Atmega32_Reg.h
 *
 * Created: 1/6/2024 12:59:38 AM
 *  Author: Taha
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

/*==========================================================================================================================================================*/

/*------------------------------>Includes<-------------------------------------*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*==========================================================================================================================================================*/

/*------------------------------>DIO REG<-------------------------------------*/
#define DDRA  (*(volatile Uint8t*)(0x3A))  // Data Direction Register for Port A
#define PORTA (*(volatile Uint8t*)(0x3B))  // Port A Register
#define PINA  (*(volatile Uint8t*)(0x39))  // Pin A Register

#define DDRB  (*(volatile Uint8t*)(0x37))  // Data Direction Register for Port B
#define PORTB (*(volatile Uint8t*)(0x38))  // Port B Register
#define PINB  (*(volatile Uint8t*)(0x36))  // Pin B Register

#define DDRC  (*(volatile Uint8t*)(0x34))  // Data Direction Register for Port C
#define PORTC (*(volatile Uint8t*)(0x35))  // Port C Register
#define PINC  (*(volatile Uint8t*)(0x33))  // Pin C Register

#define DDRD  (*(volatile Uint8t*)(0x31))  // Data Direction Register for Port D
#define PORTD (*(volatile Uint8t*)(0x32))  // Port D Register
#define PIND  (*(volatile Uint8t*)(0x30))  // Pin D Register

/*==========================================================================================================================================================*/

/*------------------------------>INT REG<-------------------------------------*/

#define SREG    (*(volatile Uint8t*) (0x5F))  // Status Register
#define GICR    (*(volatile Uint8t*) (0x5B))  // General Interrupt Control Register
#define GIFR    (*(volatile Uint8t*) (0x5A))  // General Interrupt Flag Register
#define MCUCR   (*(volatile Uint8t*) (0x55))  // MCU Control Register
#define MCUCSR  (*(volatile Uint8t*) (0x54))  // MCU Control and Status Register

/*==========================================================================================================================================================*/

/*------------------------------>ADC REG<-------------------------------------*/

#define ADMUX   (*(volatile Uint8t*) (0x27))  // ADC Multiplexer Register
#define ADCSRA  (*(volatile Uint8t*) (0x26))  // ADC Control and Status Register A
#define ADCH    (*(volatile Uint8t*) (0x25))  // ADC Data Register High
#define ADCL    (*(volatile Uint8t*) (0x24))  // ADC Data Register Low
#define ADC_DTA (*(volatile Uint16t*)(0x24))  // ADC Data Register (16-bit)

/*==========================================================================================================================================================*/

/*------------------------------>TIMER REG<-------------------------------------*/

#define TCNT0  (*(volatile Uint8t*) (0x52))  // Timer/Counter 0
#define TCCR0  (*(volatile Uint8t*) (0x53))  // Timer/Counter 0 Control Register
#define TIMSK  (*(volatile Uint8t*) (0x59))  // Timer/Counter 0 Interrupt Mask Register
#define OCR0   (*(volatile Uint8t*) (0x5C))  // Output Compare Register 0

/*==========================================================================================================================================================*/


#endif /* ATMEGA32_REG_H_ */