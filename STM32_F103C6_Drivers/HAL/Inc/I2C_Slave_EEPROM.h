/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Jan 12, 2024
 *      Author: Taha
 */

#ifndef INC_I2C_SLAVE_EEPROM_H_
#define INC_I2C_SLAVE_EEPROM_H_

#include "STM32_F103C6_I2C_Driver.h"

/* EEPROM is an I2C Slave
 * Idle Mode : devive is in high impedance state and waits for data.
 * Master Transmitter mode : the device transmits data to a slave receiver
 * Master Receiver Mode : the device receive data from a slave transmitter.*/


/* Define the EEPROM slave address as 0x2A.*/
#define EEPROM_Slave_Address 0x2A

/*Function to initialize the EEPROM module.*/
void eeprom_init(void);

/* Function to write a specified number of bytes to EEPROM
// Parameters:
//   - Memory_address: Memory address to start writing data
//   - bytes: Pointer to the data to be written
//   - Data_Length: Number of bytes to write
// Returns:
//   - An unsigned char indicating the success of the operation.*/
unsigned char eeprom_write_Nbytes(unsigned int Memory_address, uint8_t *bytes, uint8_t Data_Length);

/* Function to read a specified number of bytes from EEPROM
// Parameters:
//   - Memory_address: Memory address to start reading data
//   - dataOut: Pointer to store the read data
//   - Data_Length: Number of bytes to read
// Returns:
//   - An unsigned char indicating the success of the operation.*/
unsigned char eeprom_read_Nbytes(unsigned int Memory_address, uint8_t *dataOut, uint8_t Data_Length);

#endif /* INC_I2C_SLAVE_EEPROM_H_ */
