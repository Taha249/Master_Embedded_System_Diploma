/*
 * STM32_F103C6_SPI_Driver.h
 *
 *  Created on: Jan 1, 2024
 *      Author: Taha
 */

#ifndef INC_STM32_F103C6_SPI_DRIVER_H_
#define INC_STM32_F103C6_SPI_DRIVER_H_

/*=============Includes"=============*/
#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Generic Variables"=============*/
struct S_IRQ_SRC
{
	uint8_t TXE:1 ;			// TX buffer is empty interrupt
	uint8_t RXNE:1 ;		// RX buffer is not empty interrupt
	uint8_t ERRI:1 ;		// Error interrupt
	uint8_t Reserved:5 ;
};

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Structure Configuration"=============*/
typedef struct
{
	uint16_t Device_Mode ; /* Specifies the SPI operating mode @ref SPI Device_Mode->(Master/Slave).*/

	uint16_t Comunnication_Mode ; /*Specify the Communication Mode->(Simples/HD/FD).
	                               Set bidirectional mode  based on @ref SPI_Communication_Mode.*/

	uint16_t Frame_Format ; /* Specify LSB or MSB based on @ref SPI_Frame_Format.*/

	uint16_t DataSize ; /* Specify the data size->(8/16 bits). Set the parameter based on @ref SPI_DataSize.*/

	uint16_t CLKPolarity ; /* Specify the polarity of clock->(High/Low).
	                          Set the polarity based on @ref SPI_CLKPolarity.*/

	uint16_t CLKPhase ; /* Specify the phase of clock->(1st/2nd edge sampling).
	                       Set the phase based on @ref SPI_CLKPhase.*/

	uint16_t NSS ; /* Specify whether the NSS signal is managed by H.W(NSS pin) or S.W using the SSI bit enable.
	                  Set the NSS based on @ref SPI_NSS.*/

	uint16_t BuadRate_PreScaler ; /* Specify the baud rate Per-Scaler value which will be used to configure the transmit and receive SCK Clock.
	                                 Set the BuadRate per-scaler based on @ref SPI_BuadRate_PreScaler.
	                                  Note: Focus on to configure RCC to enter the correct clock to APB2>>to SPI1*/

	uint16_t IRQ_Enable ; /* Set based on @ref SPI_IRQ_Enable.*/

	void (*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src) ; /* Set the C function() which will be called once the IRQ happened.*/


}SPI_Config;

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Reference Macros=============*/

/* @ref SPI Device_Mode->(Master/Slave).*/
#define SPI_Device_Mode_Slave			            (0x00000000U)
#define SPI_Device_Mode_Master			            (0x1U << 2)                       /*CR1.MSTR = 1 : Master configuration.*/


/* @ref SPI_Communication_Mode->(Simplex/HD/FD).*/
#define SPI_Direction_2Line			                (0x00000000U)
#define SPI_Direction_2Line_RXonly	                (0x1U<<10)		                /*CR1. Bit 10  RXONLY : Receive only.*/
#define SPI_Direction_1Line_RXonly	                (0x1U << 15)	                /*CR1. Bit 15  BIDIMODE : Bidirectional data mode enable.*/
#define SPI_Direction_1Line_TXonly	                ((0x1U<<15) | (0x1U<<14))		/*CR1. Bit 15  BIDIMODE : Bidirectional data mode enable & CR1. Bit 14 BIDIOE : Ouput enable in bidirectional mode.*/


/* @ref SPI_Frame_Format->(LSB/MSB).*/
#define SPI_Frame_Format_MSB_Transmitted_First		(0x00000000U)
#define SPI_Frame_Format_LSB_Transmitted_First		(0x1U<<7)				        /*CR1. Bit 7 LSBFIRST : Data frame format.*/


/* @ref SPI_DataSize->(8/16 Bits).*/
#define SPI_DataSize_8BIT				            (0x00000000U)
#define SPI_DataSize_16BIT				            (0x1U<<11)				         /*CR1. Bit 11 DFF: Data Size.*/


/* @ref SPI_CLKPolarity->(High/Low).*/
#define SPI_CLKPolarity_Low_when_IDLE		        (0x00000000U)
#define SPI_CLKPolarity_High_when_IDLE		        (0x1U<<1)			              /*CR1. Bit 1 CPOL : Clock Polarity.*/


/* @ref SPI_CLKPhase->(1st/2nd edge sampling).*/
#define SPI_CLKPhase_1EDGE_first_data_capture_edge	(0x00000000U)
#define SPI_CLKPhase_2EDGE_first_data_capture_edge	(0x1U<<0)		                   /*CR1. Bit 0 CPHA : Clock phase.*/


/* @ref SPI_NSS->(H.W/S.W).*/
#define SPI_NSS_HW_Slave							(0x00000000U)
#define SPI_NSS_HW_Master_SS_output_Enable		    (0x1U<<2)				           /*CR2. Bit 2 SSOE = 1 : SS output Enable.*/
#define SPI_NSS_HW_Master_SS_output_Disable		    ~(0x1U<<2)				           /*CR2. Bit 2 SSOE = 0 : SS output Disable.*/
#define SPI_NSS_SW_NSSInternalSoft_Reset	        (0x1U<<9)						   /*CR2. Bit 9 SSM : SW SS Enable.*/
#define SPI_NSS_SW_NSSInternalSoft_set		        ((0x1U<<9) | (0x1U<<8))			   /*CR2. Bit 9 SSM : SW SS Enable & CR2. Bit 8 SSI : internal SS (1) is set (0) is Reset.*/


/* @ref SPI_BuadRate_PreScaler.*/
#define SPI_BuadRate_PreScaler_2					(0x00000000U)
#define SPI_BuadRate_PreScaler_4					(0b001U << 3)
#define SPI_BuadRate_PreScaler_8					(0b010U << 3)
#define SPI_BuadRate_PreScaler_16					(0b011U << 3)
#define SPI_BuadRate_PreScaler_32					(0b100U << 3)
#define SPI_BuadRate_PreScaler_64					(0b101U << 3)
#define SPI_BuadRate_PreScaler_128					(0b110U << 3)
#define SPI_BuadRate_PreScaler_256					(0b111U << 3)


/* @ref SPI_IRQ_Enable.*/
#define SPI_IRQ_Enable_NONE					        (0x00000000U)
#define SPI_IRQ_Enable_TXEIE				        (uint32_t)(1<<7)
#define SPI_IRQ_Enable_RXNEIE				        (uint32_t)(1<<6)
#define SPI_IRQ_Enable_ERROE	                    (uint32_t)(1<<5)


/* Polling Mechanism.*/
enum PollingMechanism
{
	POLLingEnable,
	POLLingDisable
};


/*<--------------------------------------------------------------------------------------------------------->*/

 /*=============APIs Supported by "MCAL SPI DRIVER"=============*/

/* Initialization/de-initialization functions  **********************************/

void MCAL_SPI_Init(SPI_TypeDef* SPIx, SPI_Config* SPI_Config);
void MCAL_SPI_DeInit(SPI_TypeDef* SPIx);
void MCAL_SPI_GPIO_Set_Pins (SPI_TypeDef* SPIx);
void MCAL_SPI_SendData (SPI_TypeDef* SPIx , uint16_t* pTXBuffer, enum PollingMechanism PollingEn);
void MCAL_SPI_ReceiveData (SPI_TypeDef* SPIx, uint16_t* pRXBuffer , enum PollingMechanism PollingEn);
void MCAL_SPI_TX_RX (SPI_TypeDef * SPIx, uint16_t* pTRXBuffer , enum PollingMechanism PollingEn);




#endif /* INC_STM32_F103C6_SPI_DRIVER_H_ */
