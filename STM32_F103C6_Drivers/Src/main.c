/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng.Taha mohamed
 * @brief          : Learn In Depth-> I2C_Controller
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//#define MCU_Act_As_Master
#define MCU_Act_As_Slave

#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32_F103C6_SPI_Driver.h"
#include "STM32_F103C6_I2C_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"
#include "I2C_Slave_EEPROM.h"

void delay (int x){
	int i , j ;
	for (i=0 ; i<x ; i++)
		for (j=0 ; j<50 ; j++);
}

void Clock_init (void)
{
	// Enable clock for GPIOA
	RCC_GPIOA_CLK_EN();
	// Enable clock for GPIOB
	RCC_GPIOB_CLK_EN();
	// Enable clock for AFIO
	RCC_AFIO_CLK_EN();
}


int main(void)
{
	Clock_init();

	// Test Case 1
	unsigned char ch1[] = {0x1 , 0x2 , 0x3 , 0x4 , 0x5 , 0x6 , 0x7} ;
	unsigned char ch2[7] = {0} ;

	eeprom_init();
	eeprom_write_Nbytes(0xAF, ch1, 7);
	eeprom_read_Nbytes(0xAF, ch2, 7);


	// Test Case 2

	ch1[0] = 0xA ;
	ch1[1] = 0xB ;
	ch1[2] = 0xC ;
	ch1[3] = 0xD ;

	eeprom_write_Nbytes(0xFFF, ch1, 4);
	eeprom_read_Nbytes(0xFFF, ch2, 4);

	while (1)
	{

	}
	return 0;

}
