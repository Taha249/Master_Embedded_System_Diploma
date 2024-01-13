/*
 * DIO.c
 *
 * Created: 1/6/2024 1:08:14 AM
 *  Author: Taha
 */ 

/*==========================================================================================================================================================*/
/*------------------------------>Includes<-------------------------------------*/
#include "DIO.h"
/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Set the direction (Input/Output) for a specific pin on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param pin: The pin number (DIO_PIN0 to DIO_PIN7).
 * @param direction: The desired direction (DIO_PIN_INPUT or DIO_PIN_OUTPUT).
 *******************************************************************************/
void DIO_SetPin_Direction(Uint8t port, Uint8t pin, Uint8t direction)
{
	switch(direction)
	{
		case DIO_PIN_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, pin);
			break;
		}
		break;
		case DIO_PIN_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Set the value (High/Low) for a specific output pin on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param pin: The pin number (DIO_PIN0 to DIO_PIN7).
 * @param value: The desired value (DIO_PIN_LOW or DIO_PIN_HIGH).
 *******************************************************************************/
void DIO_SetPin_Value(Uint8t port, Uint8t pin, Uint8t value)
{
	switch(value)
	{
		case DIO_PIN_LOW:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, pin);
			break;
		}
		break;
		case DIO_PIN_HIGH:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, pin);
			break;
		}
		break;
	}
}
/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Toggle the value of a specific output pin on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param pin: The pin number (DIO_PIN0 to DIO_PIN7).
 *******************************************************************************/
void DIO_TogglePin(Uint8t port, Uint8t pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		TGL_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		TGL_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		TGL_BIT(PORTD, pin);
		break;
	}
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Read the value of a specific input pin on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param pin: The pin number (DIO_PIN0 to DIO_PIN7).
 * @param value: Pointer to store the read value (DIO_PIN_LOW or DIO_PIN_HIGH).
 *******************************************************************************/
void DIO_ReadPin_Value(Uint8t port, Uint8t pin, Uint8t* value)
{
	switch(port)
	{
		case DIO_PORTA:
		*value = GET_BIT(PINA, pin);
		break;
		case DIO_PORTB:
		*value = GET_BIT(PINB, pin);
		break;
		case DIO_PORTC:
		*value = GET_BIT(PINC, pin);
		break;
		case DIO_PORTD:
		*value = GET_BIT(PIND, pin);
		break;
		
	}
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Set the direction (Input/Output) for all pins on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param direction: The desired direction for the entire port (DIO_PORT_INPUT or DIO_PORT_OUTPUT).
 *******************************************************************************/
void DIO_SetPort_Direction(Uint8t port, Uint8t direction)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = direction;
		break;
		case DIO_PORTB:
		PORTB = direction;
		break;
		case DIO_PORTC:
		PORTC = direction;
		break;
		case DIO_PORTD:
		PORTD = direction;
		break;
	}
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Set the value (High/Low) for all output pins on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param value: The desired value for the entire port (DIO_PORT_LOW or DIO_PORT_HIGH).
 *******************************************************************************/
void DIO_SetPort_Value(Uint8t port, Uint8t value)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = value;
		break;
		case DIO_PORTB:
		PORTB = value;
		break;
		case DIO_PORTC:
		PORTC = value;
		break;
		case DIO_PORTD:
		PORTD = value;
		break;
	}
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Toggle the value of all output pins on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 *******************************************************************************/
void DIO_TogglePort(Uint8t port)
{
	switch(port)
	{
		case DIO_PORTA:
		TGL_PORT(PORTA);
		break;
		case DIO_PORTB:
		TGL_PORT(PORTB);
		break;
		case DIO_PORTC:
		TGL_PORT(PORTC);
		break;
		case DIO_PORTD:
		TGL_PORT(PORTD);
		break;
	}
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Read the values of all input pins on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param value: Pointer to store the read values.
 *******************************************************************************/
void DIO_ReadPort_Value(Uint8t port, Uint8t* value)
{
	switch(port)
	{
		case DIO_PORTA:
		*value = PORTA;
		break;
		case DIO_PORTB:
		*value = PORTB;
		break;
		case DIO_PORTC:
		*value = PORTC;
		break;
		case DIO_PORTD:
		*value = PORTD;
		break;
	}
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Activate the Pull-Up resistor for a specific input pin on a given port.
 * @param port: The port identifier (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD).
 * @param pin: The pin number (DIO_PIN0 to DIO_PIN7).
 *******************************************************************************/
void DIO_SetPULLUP(Uint8t port, Uint8t pin)
{
	switch (port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, pin);
		break;
	}
}

/*==========================================================================================================================================================*/