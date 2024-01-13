/*
 * STM32_F103C6_I2C_Driver.h
 *
 *  Created on: Jan 11, 2024
 *      Author: Taha
 */

#ifndef INC_STM32_F103C6_I2C_DRIVER_H_
#define INC_STM32_F103C6_I2C_DRIVER_H_

/*=============Includes"=============*/

#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Structure Configuration"=============*/

/*Enumeration representing possible states of an I2C slave device.*/
typedef enum
{
	I2C_EV_STOP,              // I2C stop condition
	I2C_ERROR_AF,             // I2C acknowledge failure
	I2C_EV_ADDR_MATCHED,      // I2C address matched
	I2C_EV_DATA_REQ,          // I2C data request
	I2C_EV_DATA_RCV           // I2C data reception
} Slave_State;

/*Structure representing addressing details for an I2C slave device.*/
struct S_I2C_Slave_Device_Address
{
	uint16_t Duel_ADD;                        // Flag: Enable (1) or Disable (0) dual addressing
	uint16_t Primary_slave_address;           // Primary slave address of the I2C device
	uint16_t Secondary_slave_address;         // Secondary slave address of the I2C device
	uint16_t I2C_Addressing_Slave_Mode;      // Reference to I2C addressing slave mode
};


typedef struct
{
	uint32_t							ClockSpeed ;					/*Specify the clock frequency.*/
	                                                                    /*This parametar must be set based on @ref I2C_SCLK_define.*/

	uint32_t 							StretchMode;					/*Enable and disable clock stretching.*/
	                                                                    /*This parametar must be set based on @ref I2C_StretchMode_define.*/

	uint32_t							 Mode;							/*Enable and disable clock stretching.*/
	                                                                    /*This parametar must be set based on @ref I2C_Mode_define.*/

	struct S_I2C_Slave_Device_Address  	 I2C_Slave_Device_Address;		/*Set Slave Address.*/
	                                                                    /*This parametar must be set based on @ref I2C_Addressing_Slave_Mode_define.*/

	uint32_t							 ACK_Control;					/*Enable and disable ACK.*/
	                                                                    /*This parametar must be set based on @ref I2C_ACK_define.*/

	void (* P_Slave_Event_CallBack)(Slave_State state);					/*Enable and disable ACK.*/
	                                                                    /*This parametar must be set based on @ref I2C_ACK_define.*/
}I2C_Config;


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Reference Macros=============*/

// @ref I2C_SCLK_define
// Defines constants for standard and fast I2C clock speeds (50KHz, 100KHz, 200KHz, and 400KHz).
#define I2C_SCLK_SM_50K                   (50000U)
#define I2C_SCLK_SM_100K                  (100000U)
#define I2C_SCLK_FM_200K                  (200000U) // Fast Mode Not Supported yet
#define I2C_SCLK_SM_400K                  (400000U)

// @ref I2C_StretchMode_define
// Defines constants for enabling or disabling clock stretching in I2C communication.
#define I2C_StretchMode_Enable            (0x0)
#define I2C_StretchMode_Disable           I2C_CR1_NOSTRETCH

// @ref I2C_Mode_define
// Defines constants for different I2C modes, specifically I2C mode and SMBus mode.
#define I2C_Mode_I2C                      (0)
#define I2C_Mode_SMBus                    I2C_CR1_SMBUS

//@ref I2C_Addressing_Slave_Mode_define
// Bit 15 ADDMODE Addressing mode (slave mode)
// 0: 7-bit slave address (10-bit address not acknowledged)
// 1: 10-bit slave address (7-bit address not acknowledged)
#define I2C_Addressing_Slave_Mode_7BIT     0
#define I2C_Addressing_Slave_Mode_10BIT    (uint16_t)(1<<15)

// @ref I2C_ACK_define
/*I2C_CR1 >> Bit 10 ACK: Acknowledge enable
This bit is set and cleared by software and cleared by hardware when PE=0.
0: No acknowledge returned
1: Acknowledge returned after a byte is received (matched address or data)*/
#define I2C_ACK_Enable                     (I2C_CR1_ACK)
#define I2C_ACK_Disable                    0


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Generic Variables"=============*/

// Enumeration for stop conditions in I2C communication
typedef enum
{
    With_Stop,          // Stop condition included
    Without_Stop        // Stop condition not included
} Stop_Condition;

// Enumeration for types of I2C start conditions
typedef enum
{
    START,              // Regular start condition
    REPEATED_START      // Repeated start condition
} Repeated_Start;

// Enumeration for functional states (ENABLE/DISABLE)
typedef enum {

	DISABLE = 0,
	ENABLE = 1

} FunctionalState;

// Enumeration for flag status (RESET/SET)
typedef enum {

	RESET = 0,
	SET = 1

} FlagStatus;

// Enumeration for I2C direction (Transmitter/Receiver)
typedef enum {

	I2C_Direction_Transmitter = 0,
	I2C_Direction_Receiver = 1

} I2C_Direction;

// Macro defining an I2C event for master byte transmitting
#define I2C_EVENT_MASTER_BYTE_TRANSMITTING ((uint32_t)0x00070080) // Checking on "TRA, BUSY, MSL, TXE flags"

// Enumeration for various I2C status conditions
typedef enum
{
    I2C_FLAG_BUSY = 0,                              // I2C bus is busy
    EV5,                                             // Event 5: SB=1, cleared by reading SR1 register followed by writing DR register with Address
    EV6,                                             // Event 6: ADDR=1, cleared by reading SR1 register followed by reading SR2
    EV8,                                             // Event 8: TxE=1, shift register not empty, data register empty, cleared by writing DR register
    EV8_1,
    EV7,                                             // Event 7: RxNE=1
    MASTER_BYTE_TRANSMITTING = ((uint32_t)0x00070080) // Checking on "TRA, BUSY, MSL, TXE flags"
} Status;

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============APIs Supported by "MCAL I2C DRIVER"=============*/

// Initialize the I2C module with the specified configuration.
void MCAL_I2C_Init(I2C_TypeDef* I2Cx, I2C_Config * I2C_CONFIG);

// Deinitialize the I2C module.
void MCAL_I2C_DeInit(I2C_TypeDef* I2Cx);

// Configure GPIO pins for I2C communication.
void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef* I2Cx);

// Initiates a master transmission with the specified parameters.
void MCAL_I2C_Master_TX(I2C_TypeDef* I2Cx, uint16_t devAddr, uint8_t* dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start Start);

// Initiates a master reception with the specified parameters.
void MCAL_I2C_Master_RX(I2C_TypeDef* I2Cx, uint16_t devAddr, uint8_t* dataIN, uint32_t dataLen, Stop_Condition Stop, Repeated_Start Start);


// Transmits data in slave mode.
void MCAL_I2C_Slave_TX(I2C_TypeDef* I2Cx, uint8_t data);

// Receives data in slave mode.
uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef* I2Cx);


// Generates a start condition based on the specified parameters.
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState, Repeated_Start Start);

// Generates a stop condition based on the specified parameters.
void I2C_GenerateStop(I2C_TypeDef* I2Cx, FunctionalState NewState);

// Checks the status of a specific flag.
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, Status Flag);

// Sends the address byte in master mode with the specified direction.
void I2C_SendAddress(I2C_TypeDef* I2Cx, uint8_t Address, I2C_Direction Direction);

// Configures the I2C acknowledgment based on the specified state.
void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);


/*<--------------------------------------------------------------------------------------------------------->*/



#endif /* INC_STM32_F103C6_I2C_DRIVER_H_ */
