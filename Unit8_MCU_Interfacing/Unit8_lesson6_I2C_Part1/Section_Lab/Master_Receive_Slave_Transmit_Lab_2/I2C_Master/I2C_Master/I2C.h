/*
 * I2C.h
 *
 * Created: 1/6/2024 1:40:26 AM
 *  Author: Taha
 */ 


#ifndef I2C_H_
#define I2C_H_

/*==========================================================================================================================================================*/
/*------------------------------>Includes<-------------------------------------*/
#undef F_CPU
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
/*==========================================================================================================================================================*/

void I2C_INIT(unsigned long SCL_Clock);
void I2C_START(void);
void I2C_WRITE(unsigned char cByte);
unsigned char I2C_READ(unsigned char ack);
void I2C_STOP();




#endif /* I2C_H_ */