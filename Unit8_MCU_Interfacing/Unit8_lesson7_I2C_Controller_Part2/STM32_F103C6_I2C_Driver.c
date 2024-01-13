/*
 * STM32_F103C6_I2C_Driver.c
 *
 *  Created on: Jan 11, 2024
 *      Author: Taha
 */

/*=============INCLUDES=============*/

#include "STM32_F103C6_I2C_Driver.h"

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============GENERIC VARIABLES=============*/

I2C_Config Global_I2C_Config[2] = {0} ;


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============GENERIC MACROS=============*/

#define I2C1_INDEX					0
#define I2C2_INDEX					1


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============GENERIC FUNCTIONS=============*/

void I2C_GenerateSTART (I2C_TypeDef* I2Cx , FunctionalState NewState , Repeated_Start Start)
{
	if(Start != REPEATED_START)
	{
		// Check if the bus is idle
		while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));
	}
	/*
	 * I2C_CR1 >> Bit 8 START: Start generation
		This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
		In Master Mode:
		0: No Start generation
		1: Repeated start generation
		In Slave mode:
		0: No Start generation
		1: Start generation when the bus is free
	 */
	if(NewState != DISABLE)
	{
		I2Cx->CR1 |= I2C_CR1_START ;
	}else
	{
		I2Cx->CR1 &= ~(I2C_CR1_START) ;
	}

}



FlagStatus I2C_GetFlagStatus (I2C_TypeDef* I2Cx , Status Flag)
{
	FlagStatus bitstatus = RESET ;
	uint32_t flag1 = 0 , flag2 = 0 , lastevent=0 ;
	switch (Flag)
	{
	case I2C_FLAG_BUSY:
		/*I2C_SR2 >> Bit 1 BUSY: Bus busy
			0: No communication on the bus
			1: Communication ongoing on the bus
			– Set by hardware on detection of SDA or SCL low
			– cleared by hardware on detection of a Stop condition*/
		if(I2Cx->SR2 & I2C_SR2_BUSY)
			bitstatus = SET ;
		else
			bitstatus = RESET ;
		break ;
	case EV5:
		// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address
		/*  Bit 0 SB: Start bit (Master mode)
			0: No Start condition
			1: Start condition generated.
			– Set when a Start condition generated.
			– Cleared by software by reading the SR1 register followed by writing the DR register, or by
			hardware when PE=0
		 */
		if(I2Cx->SR1 & I2C_SR1_SB)
			bitstatus = SET ;
		else
			bitstatus = RESET ;
		break ;
	case EV6:
		// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
		/*Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
			This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
			when PE=0.
			Address matched (Slave)
			0: Address mismatched or not received.
			1: Received address matched.*/
		if(I2Cx->SR1 & I2C_SR1_ADDR)
			bitstatus = SET ;
		else
			bitstatus = RESET ;
		break ;
	case EV8_1:
	case EV8:
		// EV8: TxE=1, shift register not empty, d. ata register empty, cleared by writing DR registe
		if(I2Cx->SR1 & I2C_SR1_TXE)
			bitstatus = SET ;
		else
			bitstatus = RESET ;
		break ;
	case EV7 :
		// RxNE=1 Cleared by reading DR register
		if(I2Cx->SR1 & I2C_SR1_RXNE)
			bitstatus = SET ;
		else
			bitstatus = RESET ;
		break ;
	case MASTER_BYTE_TRANSMITTING :
		// Checking on " TRA , BUSY , MSL , TXE flags "
		flag1 = I2Cx->SR1 ;
		flag2 = I2Cx->SR2 ;
		flag2 = flag2 << 16 ;
		lastevent = (flag1 | flag2) & ((uint32_t)0x00FFFFFF);

		if ((lastevent & Flag ) == Flag)
			bitstatus = SET ;
		else
			bitstatus = RESET ;
		break ;

	}
	return bitstatus ;
}


void I2C_SendAddress (I2C_TypeDef* I2Cx , uint8_t Address ,  I2C_Direction Direction )
{
	uint8_t index = I2Cx == I2C1 ? I2C1_INDEX :  I2C2_INDEX ;

	if ((Global_I2C_Config[index].I2C_Slave_Device_Address.I2C_Addressing_Slave_Mode) == I2C_Addressing_Slave_Mode_7BIT)
	{
		Address = Address << 1 ;

		if(Direction != I2C_Direction_Transmitter)
		{
			Address |= 1<<0 ;
		}else{
			Address &= ~(1<<0) ;
		}

		I2Cx->DR = Address ;

	}else{
		// not supported
	}
}


void I2C_GenerateStop (I2C_TypeDef* I2Cx , FunctionalState NewState)
{
	if (NewState != DISABLE)
		I2Cx->CR1 |= I2C_CR1_STOP;
	else
		I2Cx->CR1 &= ~(I2C_CR1_STOP) ;
}


void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx , FunctionalState NewState)
{
	if (NewState != DISABLE)
		I2Cx->CR1 |= I2C_CR1_ACK;
	else
		I2Cx->CR1 &= ~(I2C_CR1_ACK) ;
}


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============APIs IMPLEMENTATION=============*/

/*=========================================================================================================
 * @brief Initializes the I2C peripheral with the provided configurations.
 *
 * This function sets up the I2C peripheral based on the specified mode, clock speed,
 * addressing mode, and other configuration parameters. It configures the clock,
 * timing parameters, control registers, and slave addresses. Additionally, it enables
 * interrupts if a callback function for slave events is provided.
 *
 * @param I2Cx Pointer to the I2C peripheral (I2C1 or I2C2) to be initialized.
 * @param I2C_CONFIG Pointer to the structure containing I2C configuration parameters.
 *
 * @note Ensure that RCC (Reset and Clock Control) macros, global configuration arrays,
 *       and NVIC (Nested Vectored Interrupt Controller) settings are defined in the
 *       codebase before using this function.
 *
 * @note Currently, only Standard Mode (Sm) with clock speeds of 50kHz and 100kHz is
 *       supported. Fast Mode (Fm) is not implemented in this version.
 =========================================================================================================*/
void MCAL_I2C_Init(I2C_TypeDef* I2Cx, I2C_Config* I2C_CONFIG)
{
    // Variables to store temporary and calculated values
    uint16_t tmpreg = 0, freqrange = 0, result = 0;
    uint32_t PCLK1 = 8000000;  // Assume a default PCLK1 frequency of 8 MHz

    // Enable RCC Clock and store configuration based on the selected I2C peripheral
    if (I2Cx == I2C1)
    {
        Global_I2C_Config[I2C1_INDEX] = *I2C_CONFIG;
        RCC_I2C1_CLK_EN();
    }
    else if (I2Cx == I2C2)
    {
        Global_I2C_Config[I2C2_INDEX] = *I2C_CONFIG;
        RCC_I2C2_CLK_EN();
    }

    // Check and configure I2C mode
    if (I2C_CONFIG->Mode == I2C_Mode_I2C)
    {
        // Timing configuration: set peripheral clock frequency and calculate FREQ bits
        tmpreg = I2Cx->CR2;
        tmpreg &= ~(I2C_CR2_FREQ);
        PCLK1 = MCAL_RCC_GetPCLK1Freq();
        freqrange = (uint16_t)((PCLK1) / 1000000);
        tmpreg |= freqrange;
        I2Cx->CR2 = tmpreg;

        // Configure clock control register (I2C_CCR) based on clock speed
        I2Cx->CR1 &= ~(I2C_CR1_PE);
        tmpreg = 0;

        // Standard Mode Calculation for Standard Clock Speeds
        if (I2C_CONFIG->ClockSpeed == I2C_SCLK_SM_50K || I2C_CONFIG->ClockSpeed == I2C_SCLK_SM_100K)
        {
            result = (uint16_t)(PCLK1 / (I2C_CONFIG->ClockSpeed << 1));
            tmpreg |= result;
            I2Cx->CCR = tmpreg;

            // RISE Timing Configuration
            I2Cx->TRISE = freqrange + 1;
        }
        else
        {
            // Fast Mode not supported yet
        }

        // CR1 Configuration: Set ACK, Mode, and Clock Stretching
        tmpreg = I2Cx->CR1;
        tmpreg |= (uint16_t)(I2C_CONFIG->ACK_Control) | (I2C_CONFIG->Mode) | (I2C_CONFIG->StretchMode);
        I2Cx->CR1 = tmpreg;

        // OAR1 & OAR2 Configuration: Set primary and secondary slave addresses
        tmpreg = 0;
        if (I2C_CONFIG->I2C_Slave_Device_Address.Duel_ADD == 1)
        {
            tmpreg = I2C_OAR2_ENDUAL;
            tmpreg |= (I2C_CONFIG->I2C_Slave_Device_Address.Secondary_slave_address << I2C_OAR2_ADD2_Pos);
            I2Cx->OAR2 = tmpreg;
        }
        tmpreg = 0;
        tmpreg |= (I2C_CONFIG->I2C_Slave_Device_Address.Primary_slave_address << 1);
        tmpreg |= (I2C_CONFIG->I2C_Slave_Device_Address.I2C_Addressing_Slave_Mode);
        I2Cx->OAR1 = tmpreg;
    }
    else
    {
        // SMBus Not Supported
    }

    // Interrupt Configuration for Slave Mode: Enable interrupts if callback function is provided
    if (I2C_CONFIG->P_Slave_Event_CallBack != NULL)
    {
        I2Cx->CR2 |= I2C_CR2_ITBUFEN;
        I2Cx->CR2 |= I2C_CR2_ITERREN;
        I2Cx->CR2 |= I2C_CR2_ITEVTEN;
        if (I2Cx == I2C1)
        {
            NVIC_IRQ31_I2C1_EV_ENABLE;
            NVIC_IRQ32_I2C1_ER_ENABLE;
        }
        else if (I2Cx == I2C2)
        {
            NVIC_IRQ33_I2C2_EV_ENABLE;
            NVIC_IRQ34_I2C2_ER_ENABLE;
        }
        I2Cx->SR1 = 0;
        I2Cx->SR2 = 0;
    }

    // Enable the selected I2C Peripheral
    I2Cx->CR1 |= I2C_CR1_PE;
}


/**=========================================================================================================
 * @brief Deinitializes the I2C peripheral by disabling interrupts, and resetting clock and associated peripherals.
 *
 * This function takes an I2C_TypeDef pointer as an argument and deinitializes the corresponding I2C peripheral
 * by disabling the relevant NVIC interrupts and resetting the clock. It is designed to be used during system
 * shutdown or when reconfiguring the I2C peripheral.
 *
 * @param I2Cx Pointer to the I2C_TypeDef structure representing the I2C peripheral to be deinitialized.
 =========================================================================================================*/
void MCAL_I2C_DeInit(I2C_TypeDef* I2Cx)
{
    // Check if the I2C peripheral is I2C1
    if (I2Cx == I2C1)
    {
        // Disable NVIC interrupts for I2C1 events and errors
        NVIC_IRQ31_I2C1_EV_DISABLE;
        NVIC_IRQ32_I2C1_ER_DISABLE;

        // Reset the clock and associated peripherals for I2C1
        RCC_I2C1_CLK_Reset();
    }
    // Check if the I2C peripheral is I2C2
    else if (I2Cx == I2C2)
    {
        // DISABLE NVIC interrupts for I2C2 events and errors
        NVIC_IRQ33_I2C2_EV_DISABLE;
        NVIC_IRQ34_I2C2_ER_DISABLE;

        // Reset the clock and associated peripherals for I2C2
        RCC_I2C2_CLK_Reset();
    }
}


/**=========================================================================================================
 * @brief Configures GPIO pins for I2C communication based on the specified I2C module.
 *
 * @param I2Cx: Pointer to the I2C_TypeDef representing the I2C module (I2C1 or I2C2).
 =========================================================================================================*/
void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef* I2Cx)
{
    // Configure GPIO pins for I2C communication based on the specified I2C module

    GPIO_PinConfig_t PINCNF; // Structure to hold GPIO pin configuration settings

    if (I2Cx == I2C1)
    {
        // I2C1 configuration

        // PB6: I2C1_SCL
        PINCNF.GPIO_PinNumber    = GPIO_PIN_6;
        PINCNF.GPIO_MODE          = GPIO_MODE_OUTPUT_AF_OD; // GPIO configured as Alternate Function, Open Drain
        PINCNF.GPIO_Output_Speed  = GPIO_SPEED_10M;  // Output speed set to 10 MHz
        MCAL_GPIO_Init(GPIOB, &PINCNF);  // Initialize GPIOB pin 6 with the specified configuration

        // PB7: I2C1_SDA
        PINCNF.GPIO_PinNumber    = GPIO_PIN_7;
        PINCNF.GPIO_MODE          = GPIO_MODE_OUTPUT_AF_OD;
        PINCNF.GPIO_Output_Speed  = GPIO_SPEED_10M;
        MCAL_GPIO_Init(GPIOB, &PINCNF);  // Initialize GPIOB pin 7 with the specified configuration
    }
    else if (I2Cx == I2C2)
    {
        // I2C2 configuration

        // PB10: I2C2_SCL
        PINCNF.GPIO_PinNumber    = GPIO_PIN_10;
        PINCNF.GPIO_MODE          = GPIO_MODE_OUTPUT_AF_OD;
        PINCNF.GPIO_Output_Speed  = GPIO_SPEED_10M;
        MCAL_GPIO_Init(GPIOB, &PINCNF);  // Initialize GPIOB pin 10 with the specified configuration

        // PB11: I2C2_SDA
        PINCNF.GPIO_PinNumber    = GPIO_PIN_11;
        PINCNF.GPIO_MODE          = GPIO_MODE_OUTPUT_AF_OD;
        PINCNF.GPIO_Output_Speed  = GPIO_SPEED_10M;
        MCAL_GPIO_Init(GPIOB, &PINCNF);  // Initialize GPIOB pin 11 with the specified configuration
    }
}


/**=========================================================================================================
 * @brief   Transmit data as a master using I2C protocol.
 * @param   I2Cx: Pointer to the I2C peripheral.
 * @param   devAddr: 7-bit device address.
 * @param   dataOut: Pointer to the data buffer to be transmitted.
 * @param   dataLen: Length of the data buffer.
 * @param   Stop: Stop condition option (With_Stop or Without_Stop).
 * @param   Start: Repeated Start condition option (Repeated_Start or No_Repeated_Start).
 * @retval  None
 =========================================================================================================*/
void MCAL_I2C_Master_TX(I2C_TypeDef* I2Cx, uint16_t devAddr, uint8_t* dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start Start)
{
    uint32_t i;

    // 1- Set the start bit in the I2C1 register to generate Start condition
    I2C_GenerateSTART(I2Cx, ENABLE, Start);

    // 2- Wait for EV5
    // EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address
    while (!I2C_GetFlagStatus(I2Cx, EV5));

    // 3- Send Address
    I2C_SendAddress(I2Cx, devAddr, I2C_Direction_Transmitter);

    // 4- Wait for EV6
    // EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
    while (!I2C_GetFlagStatus(I2Cx, EV6));

    // 5- Checking on "TRA, BUSY, MSL, TXE flags"
    while (!I2C_GetFlagStatus(I2Cx, MASTER_BYTE_TRANSMITTING));

    // 6- Send data
    for (i = 0; i < dataLen; i++)
    {
        I2Cx->DR = dataOut[i];

        // Wait for EV8
        while (!I2C_GetFlagStatus(I2Cx, EV8));
    }

    // 7- Stop Condition
    if (Stop == With_Stop)
    {
        I2C_GenerateStop(I2Cx, ENABLE);
    }
}


/**=========================================================================================================
  * @brief  Perform a master receive operation on the I2C bus.
  * @param  I2Cx: I2C instance (e.g., I2C1 or I2C2).
  * @param  devAddr: 7-bit device address.
  * @param  dataIN: Pointer to the buffer for received data.
  * @param  dataLen: Number of bytes to receive.
  * @param  Stop: Specify whether to generate a stop condition after reception.
  * @param  Start: Specify whether to generate a repeated start condition before reception.
  * @retval None
  =========================================================================================================*/
void MCAL_I2C_Master_RX(I2C_TypeDef* I2Cx, uint16_t devAddr, uint8_t* dataIN, uint32_t dataLen, Stop_Condition Stop, Repeated_Start Start)
{
    uint32_t i;
    uint8_t index = I2Cx == I2C1 ? I2C1_INDEX : I2C2_INDEX;  // Determine the I2C index

    // 1- Set the start bit in the I2C register to generate Start condition
    I2C_GenerateSTART(I2Cx, ENABLE, Start);

    // 2- Wait for EV5 (SB=1, cleared by reading SR1 register followed by writing DR register with Address)
    while (!I2C_GetFlagStatus(I2Cx, EV5));

    // 3- Send Address
    I2C_SendAddress(I2Cx, devAddr, I2C_Direction_Receiver);

    // 4- Wait for EV6 (ADDR=1, cleared by reading SR1 register followed by reading SR2)
    while (!I2C_GetFlagStatus(I2Cx, EV6));

    // 5- Receive data
    I2C_AcknowledgeConfig(I2Cx, ENABLE);  // Enable acknowledgment

    if (dataLen)
    {
        // Read until dataLen becomes zero
        for (i = dataLen; i > 1; i--)
        {
            // 5.1- Check for EV7 (RXNE=1)
            while (!I2C_GetFlagStatus(I2Cx, EV7));

            // 5.2- Read data from DR
            *dataIN = I2Cx->DR;
            dataIN++;
        }

        // Disable acknowledgment after the last byte
        I2C_AcknowledgeConfig(I2Cx, DISABLE);
    }

    // 6- Stop Condition (if specified)
    if (Stop == With_Stop)
    {
        I2C_GenerateStop(I2Cx, ENABLE);
    }

    // Re-enable acknowledgment if configured globally
    if (Global_I2C_Config[index].ACK_Control == I2C_ACK_Enable)
    {
        I2C_AcknowledgeConfig(I2Cx, ENABLE);
    }
}

/*<--------------------------------------------------------------------------------------------------------->*/


// Slave Interrupt Mechanism

void MCAL_I2C_Slave_TX (I2C_TypeDef* I2Cx , uint8_t data)
{
	I2Cx->DR = data ;
}
uint8_t MCAL_I2C_Slave_RX (I2C_TypeDef* I2Cx)
{
	return (uint8_t) I2Cx->DR ;
}


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============IRQ=============*/
void I2C1_ER_IRQHandler()
{

}
void I2C1_EV_IRQHandler()
{


}
void I2C2_EV_IRQHandler()
{


}
void I2C2_ER_IRQHandler ()
{


}




/*<--------------------------------------------------------------------------------------------------------->*/
/*<--------------------------------------------------------------------------------------------------------->*/



