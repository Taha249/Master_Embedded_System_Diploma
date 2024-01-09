/*
 * I2C.c
 *
 * Created: 1/6/2024 1:40:36 AM
 *  Author: Taha
 */ 

#include "I2C.h"
#define prescaler 1 //1 4 16 64


/********************************************************************************
 * @brief Initialize the I2C communication with the specified SCL clock frequency.
 * @param SCL_Clock: The desired SCL clock frequency in Hz.
 * 
 * This function configures the I2C peripheral to operate with the given SCL clock frequency.
 * It calculates the appropriate prescaler value based on the provided clock frequency.
 *******************************************************************************/

void I2C_INIT(unsigned long SCL_Clock)
{
    TWBR = (unsigned char)(((F_CPU / SCL_Clock) - 16) / (2 * prescaler));
    
	switch(prescaler)
	{
		case 0 :
		        TWSR=0;
		        break;
		case 4 :
		        TWSR=1;
		        break;
		case 16 :
		        TWSR=2;
		        break;
		case 64 :
		        TWSR=3;
		        break;
		default :
		        TWSR=0;
				break;
		
	}
	
		   
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Generate a START condition on the I2C bus.
 * 
 * This function sends the START condition to initiate communication on the I2C bus.
 * It waits for the completion of the START condition transmission.
 *******************************************************************************/

void I2C_START(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while ((TWCR & (1 << TWINT)) == 0); // Wait for the completion of the START condition transmission
    while ((TWSR) != 0x08);              // Start Condition has Been Transmitted
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Write a byte on the I2C bus.
 * @param cByte: The byte to be written on the bus.
 * 
 * This function writes a byte onto the I2C bus. It waits for the completion of the write operation.
 *******************************************************************************/

void I2C_WRITE(unsigned char cByte)
{
    TWDR = cByte;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while ((TWCR & 0x80) == 0); // Wait for the completion of the write operation
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Generate a STOP condition on the I2C bus.
 * 
 * This function sends the STOP condition to terminate communication on the I2C bus.
 *******************************************************************************/

void I2C_STOP()
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

/*==========================================================================================================================================================*/