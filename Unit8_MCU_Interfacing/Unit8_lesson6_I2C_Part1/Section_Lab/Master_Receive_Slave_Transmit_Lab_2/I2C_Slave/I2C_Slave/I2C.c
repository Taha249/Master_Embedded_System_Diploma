/*
 * I2C.c
 *
 * Created: 1/6/2024 1:55:45 AM
 *  Author: Taha
 */ 

#include "I2C.h"

/********************************************************************************
 * @brief Set the I2C address for the device to be used in the slave mode.
 * @param address: The desired I2C address for the device.
 * 
 * This function sets the I2C address for the device when operating in the slave mode.
 *******************************************************************************/
void I2C_Set_Address(unsigned char address)
{
    TWAR = address;
}

/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Read a byte on the I2C bus with the option to send an ACK/NACK.
 * @param ack: Acknowledge flag (1 to send ACK, 0 to send NACK).
 * @return The byte read from the I2C bus.
 * 
 * This function reads a byte from the I2C bus. The ack parameter specifies whether to
 * send an ACK or NACK after receiving the byte. It waits for the completion of the operation.
 *******************************************************************************/
unsigned char I2C_Read(unsigned char ack)
{
    unsigned char y = 0;

    // Set acknowledge bit and enable TWI
    TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
    
    // Wait for TWINT flag to be set
    while ((TWCR & (1 << TWINT)) == 0);

    // Store status for debugging (optional)
    while ((TWSR) != 0x60) y = TWSR;  // Own SLA+W(0) has been transmitted, and ACK has been returned
    
    // Set acknowledge bit and enable TWI for the next byte
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    
    // Wait for TWINT flag to be set
    while ((TWCR & (1 << TWINT)) == 0);

    // Store status for debugging (optional)
    while ((TWSR) != 0x80) y = TWSR;  // Data has been received, and ACK has been returned
    
    // Return received data
    return TWDR;
}


/*==========================================================================================================================================================*/

/********************************************************************************
 * @brief Write a byte to the I2C bus.
 * @param cByte: The byte to be transmitted.
 * 
 * This function is designed to write a byte to the I2C bus. It sets the TWI data register (TWDR)
 * with the provided byte, triggers the transmission by setting the TWI interrupt flag (TWINT),
 * and waits for the completion of the operation.
  *******************************************************************************/

void I2C_Write(unsigned char cByte)
{
    // Load the byte to be transmitted into the TWI data register (TWDR)
    TWDR = cByte;

    // Trigger TWI transmission by setting the TWI interrupt flag (TWINT) and enabling TWI (TWEN)
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Wait for TWI interrupt flag to be set, indicating transmission completion
    while ((TWCR & (1 << TWINT)) == 0);
}

/*==========================================================================================================================================================*/