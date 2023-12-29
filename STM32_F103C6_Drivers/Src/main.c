/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
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
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "lcd.h"

unsigned int IRQ_Flag = 0 ;
unsigned ch ;


void UART_IRQ_Callback (struct  UART_IRQ_Event* flag)
{

	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);

}

int main(void)
{

	//Enable CLock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	UART_Config uartCFG ;
	uartCFG.BaudRate = UART_BaudRate_115200 ;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE ;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_RXNEIE ;
	uartCFG.P_IRQ_CallBack = UART_IRQ_Callback ;
	uartCFG.Parity =UART_Parity__NONE ;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits__1 ;
	uartCFG.USART_Mode = UART_MODE_TX_RX ;

	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	/* Loop forever */
	while(1)
	{

	}

}
