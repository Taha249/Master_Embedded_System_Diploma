/*
 * DIO_CONFIG.h
 *
 * Created: 1/6/2024 1:08:42 AM
 *  Author: Taha
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/*==========================================================================================================================================================*/
/*------------------------------>Includes<-------------------------------------*/
#undef F_CPU 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Atmega32_Reg.h"
#include "DIO.h"
/*==========================================================================================================================================================*/

/* DIO PORTS */
#define DIO_PORTA 0      // Symbolic name for PORTA with value 0
#define DIO_PORTB 1      // Symbolic name for PORTB with value 1
#define DIO_PORTC 2      // Symbolic name for PORTC with value 2
#define DIO_PORTD 3      // Symbolic name for PORTD with value 3

/* DIO PINS */
#define DIO_PIN0 0       // Symbolic name for Pin 0 with value 0
#define DIO_PIN1 1       // Symbolic name for Pin 1 with value 1
#define DIO_PIN2 2       // Symbolic name for Pin 2 with value 2
#define DIO_PIN3 3       // Symbolic name for Pin 3 with value 3
#define DIO_PIN4 4       // Symbolic name for Pin 4 with value 4
#define DIO_PIN5 5       // Symbolic name for Pin 5 with value 5
#define DIO_PIN6 6       // Symbolic name for Pin 6 with value 6
#define DIO_PIN7 7       // Symbolic name for Pin 7 with value 7

/* DIO PIN State */
#define DIO_PIN_LOW  0   // Symbolic name for Low state with value 0
#define DIO_PIN_HIGH 1   // Symbolic name for High state with value 1

/* DIO PIN Direction */
#define DIO_PIN_INPUT  0 // Symbolic name for Input direction with value 0
#define DIO_PIN_OUTPUT 1 // Symbolic name for Output direction with value 1

/* DIO PORT State */
#define DIO_PORT_LOW  0x00  /* 0000 0000 */  // Symbolic name for Low state for a port with value 0x00
#define DIO_PORT_HIGH 0xFF /* 1111 1111 */  // Symbolic name for High state for a port with value 0xFF

/* DIO PORT Direction */
#define DIO_PORT_INPUT  0x00   // Symbolic name for Input direction for a port with value 0x00
#define DIO_PORT_OUTPUT 0xFF   // Symbolic name for Output direction for a port with value 0xFF

/*==========================================================================================================================================================*/

#endif /* DIO_CONFIG_H_ */