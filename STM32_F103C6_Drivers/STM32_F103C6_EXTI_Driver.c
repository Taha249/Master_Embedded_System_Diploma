/*
 * STM32_F103C6_EXTI_Driver.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Taha
 */

#include "stm32f103x6.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_GPIO_Driver.h"


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============GENERIC VARIABLES=============*/
/* GP_IRQ_CallBack[15] is an array of 15 elements of pointer to function take void
 * and return void also.
 */
void(* GP_IRQ_CallBack[15])(void) ;

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============GENERIC MACROS=============*/

#define AFIO_GPIO_EXTI_Mapping(x)  ((x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0 )

/*<--------------------------------------------------------------------------------------------------------->*/


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============GENERIC FUNCTIONS=============*/

void EN_NVIC(uint8_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_ENABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_ENABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_ENABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_ENABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_ENABLE;
		break;
	case 5:case 6:case 7:case 8:case 9:
		NVIC_IRQ23_EXTI9_5_ENABLE;
		break;
	case 10:case 11:case 12:case 13:case 14:case 15:
		NVIC_IRQ40_EXTI15_10_ENABLE;
		break;
	}
}

void DISEN_NVIC(uint8_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_DISABLE;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_DISABLE;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_DISABLE;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_DISABLE;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_DISABLE;
		break;
	case 5:case 6:case 7:case 8:case 9:
		NVIC_IRQ23_EXTI9_5_DISABLE;
		break;
	case 10:case 11:case 12:case 13:case 14:case 15:
		NVIC_IRQ40_EXTI15_10_DISABLE;
		break;
	}
}


void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	/* 1- Configure GPIO to be AF input -> Floating Input */
	GPIO_PinConfig_t pinCfg                                       ;
	/* Update the GPIO pin to be Floating input.*/
	pinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN        ;
	pinCfg.GPIO_MODE      = GPIO_MODE_INPUT_FLO                   ;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.EXTI_GPIO, &pinCfg)      ;
	//==============================================================

	/* 2- Update AFIO to ROUTE BETWEEN EXTI LINE WITH PORT A , B , C , D */
	/* To get the register that contain the EXTI_LINE.*/
	uint8_t AFIO_EXTICR_Index = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) / 4 ;
	/* To get the position of the bits for specified EXTI_LINE.*/
	uint8_t AFIO_EXTICR_Position = ((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) % 4) * 4 ;
	// Clear the 4 bits
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF <<AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.EXTI_GPIO) &0xF) << AFIO_EXTICR_Position) ;
	//==============================================================

	/* 3- Update Rising or Falling registers.*/
	EXTI->RTSR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber); // Rising
	EXTI->FTSR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber); //Falling

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)
	{
		EXTI->RTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber); // Rising
	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber); //Falling
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->RTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber); // Rising
		EXTI->FTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber); //Falling
	}
	//==============================================================

	/* 4- Update IRQ Handling CallBack.*/
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack ;

	//==============================================================

	/* 5- Enable and Disable IRQ EXTI & NVIC */
	if (EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) ;
		EN_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) ;
	}
	else
	{
		EXTI->IMR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) ;
		DISEN_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) ;
	}




}

/*<--------------------------------------------------------------------------------------------------------->*/


/*<--------------------------------------------------------------------------------------------------------->*/

/*=============APIs FUNCTIONS DEFINITIONS=============*/

/*<--------------------------------------------------------------------------------------------------------->*/


/*<--------------------------------------------------------------------------------------------------------->*/

/*=========================================================================================================*/
/* @Fn			  -MCAL_EXTI_GPIO_DEINIT
 * @brief 		  -reset EXTI registers and NVIC corresponding IRQ Mask.
 * @retval 		  -none
 * Note			  -none
 */
/*=========================================================================================================*/

void MCAL_EXTI_GPIO_DEINIT(void)
{
	/*  Interrupt mask register (EXTI_IMR)
        Address offset: 0x00
        Reset value: 0x0000 0000
	 */

	EXTI->IMR =  0x00000000     ;

	/* Event mask register (EXTI_EMR)
       Address offset: 0x04
       Reset value: 0x0000 0000
	 */

	EXTI->EMR = 0x00000000     ;

	/* Rising trigger selection register (EXTI_RTSR)
       Address offset: 0x08
       Reset value: 0x0000 0000
	 */

	EXTI->RTSR = 0x00000000     ;

	/* Falling trigger selection register (EXTI_FTSR)
       Address offset: 0x0C
       Reset value: 0x0000 0000
	 */

	EXTI->FTSR = 0x00000000     ;

	/* Software interrupt event register (EXTI_SWIER)
       Address offset: 0x10
       Reset value: 0x0000 0000
	 */

	EXTI->SWIER = 0x00000000     ;

	/* Pending register (EXTI_PR)
       Address offset: 0x14
       Reset value: undefined
       This bit is set when the selected edge event arrives on the external interrupt line. This bit is
       cleared by writing a ‘1’ into the bit.
	 */

	EXTI->PR = 0xFFFFFFFF        ;

}

/*<--------------------------------------------------------------------------------------------------------->*/

/*=========================================================================================================*/
/* @Fn				-MCAL_EXTI_GPIO_INIT
 * @brief 			-This is used to initialize EXTI from specific GPIO and specify the Mask/Trigger condition and IRQ callback.
 * @param [in] 		-EXTI Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define.
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules.
 *                   But LQFP48 has only GPIO A,B and part of C/D exported as external pins from the MCU.
 *                   And also mandatory to enable RCC clock for AFIO and the corresponding GPIO.
 */
/*=========================================================================================================*/

void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

/*<--------------------------------------------------------------------------------------------------------->*/

/*=========================================================================================================*/
/* @Fn				-MCAL_EXTI_GPIO_UPDATE
 * @brief 			-This is used to initialize EXTI from specific GPIO and specify the Mask/Trigger condition and IRQ callback.
 * @param [in] 		-EXTI Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define.
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules.
 *                   But LQFP48 has only GPIO A,B and part of C/D exported as external pins from the MCU.
 *                   And also mandatory to enable RCC clock for AFIO and the corresponding GPIO.
 */
/*=========================================================================================================*/

void MCAL_EXTI_GPIO_UPDATE(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);

}

/*<--------------------------------------------------------------------------------------------------------->*/

//----------------------------------------------------------------------------------------
/*===============================> ISR Functions <======================================*/
//----------------------------------------------------------------------------------------

void EXTI0_IRQHandler (void)
{
	/* Cleared by writing a ‘1’ into the bit. Pending register (EXTI_PR) */
	EXTI->PR |= 1<<0 ;
	/* Call IRQ_CallBack. */
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler (void)
{
	/* Cleared by writing a ‘1’ into the bit. Pending register (EXTI_PR) */
	EXTI->PR |= 1<<1 ;
	/* Call IRQ_CallBack. */
	GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler (void)
{
	/* Cleared by writing a ‘1’ into the bit. Pending register (EXTI_PR) */
	EXTI->PR |= 1<<2 ;
	/* Call IRQ_CallBack. */
	GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler (void)
{
	/* Cleared by writing a ‘1’ into the bit. Pending register (EXTI_PR) */
	EXTI->PR |= 1<<3 ;
	/* Call IRQ_CallBack. */
	GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler (void)
{
	/* Cleared by writing a ‘1’ into the bit. Pending register (EXTI_PR) */
	EXTI->PR |= 1<<4 ;
	/* Call IRQ_CallBack. */
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler (void)
{
	if (EXTI->PR & 1<<5) { EXTI->PR |= (1<<5) ; GP_IRQ_CallBack[5]() ; }
	if (EXTI->PR & 1<<6) { EXTI->PR |= (1<<6) ; GP_IRQ_CallBack[6]() ; }
	if (EXTI->PR & 1<<7) { EXTI->PR |= (1<<7) ; GP_IRQ_CallBack[7]() ; }
	if (EXTI->PR & 1<<8) { EXTI->PR |= (1<<8) ; GP_IRQ_CallBack[8]() ; }
	if (EXTI->PR & 1<<9) { EXTI->PR |= (1<<9) ; GP_IRQ_CallBack[9]() ; }
}

void EXTI15_10_IRQHandler (void)
{
	if (EXTI->PR & 1<<10) { EXTI->PR |= (1<<10) ; GP_IRQ_CallBack[10]() ; }
	if (EXTI->PR & 1<<11) { EXTI->PR |= (1<<11) ; GP_IRQ_CallBack[11]() ; }
	if (EXTI->PR & 1<<12) { EXTI->PR |= (1<<12) ; GP_IRQ_CallBack[12]() ; }
	if (EXTI->PR & 1<<13) { EXTI->PR |= (1<<13) ; GP_IRQ_CallBack[13]() ; }
	if (EXTI->PR & 1<<14) { EXTI->PR |= (1<<14) ; GP_IRQ_CallBack[14]() ; }
	if (EXTI->PR & 1<<15) { EXTI->PR |= (1<<15) ; GP_IRQ_CallBack[15]() ; }


}








/*<--------------------------------------------------------------------------------------------------------->*/











