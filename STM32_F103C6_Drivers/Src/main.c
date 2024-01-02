/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng.Taha mohamed
 * @brief          : Learn In Depth-> SPI_Controller
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
// Terminal <----> USART1 ->MCU1 : (SPI1 Master) ---> (SPI2 Slave) : MCU2 ---> Terminal2
/*******************************************************************************/

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
#include "lcd.h"

unsigned int IRQ_Flag = 0 ;
unsigned ch ;


void SPI1_IRQ_Callback (struct S_IRQ_SRC irq_src )
{
#ifdef MCU_Act_As_Slave
	if(irq_src.RXNE)
	{
		ch = 0xf ;
		MCAL_SPI_TX_RX(SPI1,  (uint16_t *)&ch, POLLingDisable) ;
		MCAL_UART_SendData(USART1,  (uint16_t *)&ch, enable) ;
	}
#endif
}



void UART_IRQ_Callback (struct  UART_IRQ_Event* flag)
{

	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
	/* Send to SPI. */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0) ;
	MCAL_SPI_TX_RX(SPI1	, (uint16_t *)&ch , POLLingEnable) ;
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;

}

int main(void)
{

	//Enable CLock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	/* ----------------------------> UART INIT <----------------------------------*/
	/* PA9 : UART1_TX
	 * PA10: UART1_RX
	 * PA11: UART1_CTS
	 * PA12: UART1_RTS
	 */

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

	/* ----------------------------> SPI INIT <----------------------------------*/
	/* PA4 : SPI1_NSS
	 * PA5 : SPI1_SCK
	 * PA6 : SPI_MISO
	 * PA7 : SPI_MOSI
	 */

	SPI_Config spi1_cfg ;

	spi1_cfg.CLKPhase = SPI_CLKPhase_2EDGE_first_data_capture_edge ;
	spi1_cfg.CLKPolarity = SPI_CLKPolarity_High_when_IDLE ;
	spi1_cfg.DataSize = SPI_DataSize_8BIT ;
	spi1_cfg.Frame_Format = SPI_Frame_Format_MSB_Transmitted_First ;
	spi1_cfg.BuadRate_PreScaler = SPI_BuadRate_PreScaler_8 ;
	spi1_cfg.Comunnication_Mode = SPI_Direction_2Line	 ;

#ifdef MCU_Act_As_Master
	spi1_cfg.Device_Mode = SPI_Device_Mode_Master ;
	spi1_cfg.IRQ_Enable = SPI_IRQ_Enable_NONE ;
	spi1_cfg.NSS = SPI_NSS_SW_NSSInternalSoft_set ;
	spi1_cfg.P_IRQ_CallBack = NULL ;

	/*Configure SS on PortA pin 4 by GPIO. */

	GPIO_PinConfig_t pincfg ;
	pincfg.GPIO_PinNumber = GPIO_PIN_4 ;
	pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	/* Force the SS (High) idle Mode. */
	MCAL_GPIO_Init(GPIOA, &pincfg) ;
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;


#endif

#ifdef MCU_Act_As_Slave
	spi1_cfg.Device_Mode = SPI_Device_Mode_Slave ;
	spi1_cfg.IRQ_Enable = SPI_IRQ_Enable_RXNEIE ;
	spi1_cfg.NSS = SPI_NSS_HW_Slave ;
	spi1_cfg.P_IRQ_CallBack = SPI1_IRQ_Callback ;
#endif

	MCAL_SPI_Init(SPI1, &spi1_cfg);
	MCAL_SPI_GPIO_Set_Pins(SPI1);


	while(1)
	{

	}

}
