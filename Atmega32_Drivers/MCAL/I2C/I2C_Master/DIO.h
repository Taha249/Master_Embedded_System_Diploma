/*
 * DIO.h
 *
 * Created: 1/6/2024 1:08:03 AM
 *  Author: Taha
 */ 


#ifndef DIO_H_
#define DIO_H_


/*==========================================================================================================================================================*/
/*------------------------------>Includes<-------------------------------------*/
#include "DIO_CONFIG.h"
/*==========================================================================================================================================================*/


void DIO_SetPin_Direction(Uint8t port, Uint8t pin, Uint8t direction);
void DIO_SetPin_Value(Uint8t port, Uint8t pin, Uint8t value);
void DIO_TogglePin(Uint8t port, Uint8t pin);
void DIO_ReadPin_Value(Uint8t port, Uint8t pin, Uint8t* value);
void DIO_SetPort_Direction(Uint8t port, Uint8t direction);
void DIO_SetPort_Value(Uint8t port, Uint8t value);
void DIO_TogglePort(Uint8t port);
void DIO_ReadPort_Value(Uint8t port, Uint8t* value);
void DIO_SetPULLUP(Uint8t port, Uint8t pin);

/*==========================================================================================================================================================*/

#endif /* DIO_H_ */