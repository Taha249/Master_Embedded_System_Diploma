/*
 * STM32_F103C6_EXTI_Driver.h
 *
 *  Created on: Dec 15, 2023
 *      Author: Taha
 */

#ifndef INC_STM32_F103C6_EXTI_DRIVER_H_
#define INC_STM32_F103C6_EXTI_DRIVER_H_

/*=============Includes=============*/

#include "stm32f103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Type Definition Of Inputs=============*/

typedef struct
{
	uint16_t        EXTI_InputLineNumber ;
	GPIO_TypeDef*   EXTI_GPIO            ;
	uint16_t        GPIO_PIN             ;
	uint8_t         IVT_IRQ_Number       ;


}EXTI_GPIO_MAPPING_t; // Mapping GPIO pin number with the EXTI line number

typedef struct
{
	EXTI_GPIO_MAPPING_t EXTI_PIN         ; /* Specifies the external interrupt GPIO mapping. This parameter must be based on @ref EXTI_define.*/
	uint8_t             Trigger_Case     ; /* Specifies Rising or Falling or both trigger. This parameter must be set based on @ref EXTI_Trigger_define.*/
	uint8_t             IRQ_EN           ; /* Enable or Disable the EXTI_IRQ (That will enable the IRQ MASK in EXTI and also on the NVIC interrupt controller. This parameter must be set based on @ref EXTI_IRQ_definr.*/
    void(*P_IRQ_CallBack)(void)          ; /* Set the C function() which will be called once the IRQ happen.*/


}EXTI_PinConfig_t;

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============Reference Macros=============*/

/* @ref EXTI_define */
//EXTI0
#define EXTI0PA0       (EXTI_GPIO_MAPPING_t){EXTI0, GPIOA, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PB0       (EXTI_GPIO_MAPPING_t){EXTI0, GPIOB, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PC0       (EXTI_GPIO_MAPPING_t){EXTI0, GPIOC, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PD0       (EXTI_GPIO_MAPPING_t){EXTI0, GPIOD, GPIO_PIN_0, EXTI0_IRQ}


 //EXTI1
#define EXTI1PA1       (EXTI_GPIO_MAPPING_t){EXTI1, GPIOA, GPIO_PIN_1, EXTI0_IRQ}
#define EXTI1PB1       (EXTI_GPIO_MAPPING_t){EXTI1, GPIOB, GPIO_PIN_1, EXTI0_IRQ}
#define EXTI1PC1       (EXTI_GPIO_MAPPING_t){EXTI1, GPIOC, GPIO_PIN_1, EXTI0_IRQ}
#define EXTI1PD1       (EXTI_GPIO_MAPPING_t){EXTI1, GPIOD, GPIO_PIN_1, EXTI0_IRQ}


 //EXTI2
#define EXTI2PA2       (EXTI_GPIO_MAPPING_t){EXTI2, GPIOA, GPIO_PIN_2, EXTI0_IRQ}
#define EXTI2PB2       (EXTI_GPIO_MAPPING_t){EXTI2, GPIOB, GPIO_PIN_2, EXTI0_IRQ}
#define EXTI2PC2       (EXTI_GPIO_MAPPING_t){EXTI2, GPIOC, GPIO_PIN_2, EXTI0_IRQ}
#define EXTI2PD2       (EXTI_GPIO_MAPPING_t){EXTI2, GPIOD, GPIO_PIN_2, EXTI0_IRQ}


 //EXTI3
#define EXTI3PA3       (EXTI_GPIO_MAPPING_t){EXTI3, GPIOA, GPIO_PIN_3, EXTI0_IRQ}
#define EXTI3PB3       (EXTI_GPIO_MAPPING_t){EXTI3, GPIOB, GPIO_PIN_3, EXTI0_IRQ}
#define EXTI3PC3       (EXTI_GPIO_MAPPING_t){EXTI3, GPIOC, GPIO_PIN_3, EXTI0_IRQ}
#define EXTI3PD3       (EXTI_GPIO_MAPPING_t){EXTI3, GPIOD, GPIO_PIN_3, EXTI0_IRQ}


 //EXTI4
#define EXTI4PA4       (EXTI_GPIO_MAPPING_t){EXTI4, GPIOA, GPIO_PIN_4, EXTI0_IRQ}
#define EXTI4PB4       (EXTI_GPIO_MAPPING_t){EXTI4, GPIOB, GPIO_PIN_4, EXTI0_IRQ}
#define EXTI4PC4       (EXTI_GPIO_MAPPING_t){EXTI4, GPIOC, GPIO_PIN_4, EXTI0_IRQ}
#define EXTI4PD4       (EXTI_GPIO_MAPPING_t){EXTI4, GPIOD, GPIO_PIN_4, EXTI0_IRQ}


 //EXTI5
#define EXTI5PA5       (EXTI_GPIO_MAPPING_t){EXTI5, GPIOA, GPIO_PIN_5, EXTI0_IRQ}
#define EXTI5PB5       (EXTI_GPIO_MAPPING_t){EXTI5, GPIOB, GPIO_PIN_5, EXTI0_IRQ}
#define EXTI5PC5       (EXTI_GPIO_MAPPING_t){EXTI5, GPIOC, GPIO_PIN_5, EXTI0_IRQ}
#define EXTI5PD5       (EXTI_GPIO_MAPPING_t){EXTI5, GPIOD, GPIO_PIN_5, EXTI0_IRQ}


 //EXTI6
#define EXTI6PA6       (EXTI_GPIO_MAPPING_t){EXTI6, GPIOA, GPIO_PIN_6, EXTI0_IRQ}
#define EXTI6PB6       (EXTI_GPIO_MAPPING_t){EXTI6, GPIOB, GPIO_PIN_6, EXTI0_IRQ}
#define EXTI6PC6       (EXTI_GPIO_MAPPING_t){EXTI6, GPIOC, GPIO_PIN_6, EXTI0_IRQ}
#define EXTI6PD6       (EXTI_GPIO_MAPPING_t){EXTI6, GPIOD, GPIO_PIN_6, EXTI0_IRQ}


 //EXTI7
#define EXTI7PA7       (EXTI_GPIO_MAPPING_t){EXTI7, GPIOA, GPIO_PIN_7, EXTI0_IRQ}
#define EXTI7PB7       (EXTI_GPIO_MAPPING_t){EXTI7, GPIOB, GPIO_PIN_7, EXTI0_IRQ}
#define EXTI7PC7       (EXTI_GPIO_MAPPING_t){EXTI7, GPIOC, GPIO_PIN_7, EXTI0_IRQ}
#define EXTI7PD7       (EXTI_GPIO_MAPPING_t){EXTI7, GPIOD, GPIO_PIN_7, EXTI0_IRQ}


 //EXTI8
#define EXTI8PA8       (EXTI_GPIO_MAPPING_t){EXTI8, GPIOA, GPIO_PIN_8, EXTI0_IRQ}
#define EXTI8PB8       (EXTI_GPIO_MAPPING_t){EXTI8, GPIOB, GPIO_PIN_8, EXTI0_IRQ}
#define EXTI8PC8       (EXTI_GPIO_MAPPING_t){EXTI8, GPIOC, GPIO_PIN_8, EXTI0_IRQ}
#define EXTI8PD8       (EXTI_GPIO_MAPPING_t){EXTI8, GPIOD, GPIO_PIN_8, EXTI0_IRQ}


 //EXTI9
#define EXTI9PA9       (EXTI_GPIO_MAPPING_t){EXTI9, GPIOA, GPIO_PIN_9, EXTI0_IRQ}
#define EXTI9PB9       (EXTI_GPIO_MAPPING_t){EXTI9, GPIOB, GPIO_PIN_9, EXTI0_IRQ}
#define EXTI9PC9       (EXTI_GPIO_MAPPING_t){EXTI9, GPIOC, GPIO_PIN_9, EXTI0_IRQ}
#define EXTI9PD9       (EXTI_GPIO_MAPPING_t){EXTI9, GPIOD, GPIO_PIN_9, EXTI0_IRQ}


 //EXTI10
#define EXTI10PA10       (EXTI_GPIO_MAPPING_t){EXTI10, GPIOA, GPIO_PIN_10, EXTI0_IRQ}
#define EXTI10PB10       (EXTI_GPIO_MAPPING_t){EXTI10, GPIOB, GPIO_PIN_10, EXTI0_IRQ}
#define EXTI10PC10       (EXTI_GPIO_MAPPING_t){EXTI10, GPIOC, GPIO_PIN_10, EXTI0_IRQ}
#define EXTI10PD10       (EXTI_GPIO_MAPPING_t){EXTI10, GPIOD, GPIO_PIN_10, EXTI0_IRQ}


 //EXTI11
#define EXTI11PA11       (EXTI_GPIO_MAPPING_t){EXTI11, GPIOA, GPIO_PIN_11, EXTI0_IRQ}
#define EXTI11PB11       (EXTI_GPIO_MAPPING_t){EXTI11, GPIOB, GPIO_PIN_11, EXTI0_IRQ}
#define EXTI11PC11       (EXTI_GPIO_MAPPING_t){EXTI11, GPIOC, GPIO_PIN_11, EXTI0_IRQ}
#define EXTI11PD11       (EXTI_GPIO_MAPPING_t){EXTI11, GPIOD, GPIO_PIN_11, EXTI0_IRQ}


 //EXTI12
#define EXTI12PA12       (EXTI_GPIO_MAPPING_t){EXTI12, GPIOA, GPIO_PIN_12, EXTI0_IRQ}
#define EXTI12PB12       (EXTI_GPIO_MAPPING_t){EXTI12, GPIOB, GPIO_PIN_12, EXTI0_IRQ}
#define EXTI12PC12       (EXTI_GPIO_MAPPING_t){EXTI12, GPIOC, GPIO_PIN_12, EXTI0_IRQ}
#define EXTI12PD12       (EXTI_GPIO_MAPPING_t){EXTI12, GPIOD, GPIO_PIN_12, EXTI0_IRQ}


 //EXTI13
#define EXTI13PA13       (EXTI_GPIO_MAPPING_t){EXTI13, GPIOA, GPIO_PIN_13, EXTI0_IRQ}
#define EXTI13PB13       (EXTI_GPIO_MAPPING_t){EXTI13, GPIOB, GPIO_PIN_13, EXTI0_IRQ}
#define EXTI13PC13       (EXTI_GPIO_MAPPING_t){EXTI13, GPIOC, GPIO_PIN_13, EXTI0_IRQ}
#define EXTI13PD13       (EXTI_GPIO_MAPPING_t){EXTI13, GPIOD, GPIO_PIN_13, EXTI0_IRQ}


 //EXTI14
#define EXTI14PA14       (EXTI_GPIO_MAPPING_t){EXTI14, GPIOA, GPIO_PIN_14, EXTI0_IRQ}
#define EXTI14PB14       (EXTI_GPIO_MAPPING_t){EXTI14, GPIOB, GPIO_PIN_14, EXTI0_IRQ}
#define EXTI14PC14       (EXTI_GPIO_MAPPING_t){EXTI14, GPIOC, GPIO_PIN_14, EXTI0_IRQ}
#define EXTI14PD14       (EXTI_GPIO_MAPPING_t){EXTI14, GPIOD, GPIO_PIN_14, EXTI0_IRQ}


 //EXTI15
#define EXTI15PA15       (EXTI_GPIO_MAPPING_t){EXTI15, GPIOA, GPIO_PIN_15, EXTI0_IRQ}
#define EXTI15PB15       (EXTI_GPIO_MAPPING_t){EXTI15, GPIOB, GPIO_PIN_15, EXTI0_IRQ}
#define EXTI15PC15       (EXTI_GPIO_MAPPING_t){EXTI15, GPIOC, GPIO_PIN_15, EXTI0_IRQ}
#define EXTI15PD15       (EXTI_GPIO_MAPPING_t){EXTI15, GPIOD, GPIO_PIN_15, EXTI0_IRQ}


//@ref EXTI_Trigger_define
#define EXTI_Trigger_Rising                      0
#define EXTI_Trigger_Falling                     1
#define EXTI_Trigger_RisingAndFalling            2


//@ref EXTI_IRQ_define
#define EXTI_IRQ_Enable                          1
#define EXTI_IRQ_Disable                         0

/*<--------------------------------------------------------------------------------------------------------->*/

/*=============APIs Supported by "MCAL GPIO DRIVER"=============*/

void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t* EXTI_Config)  ;
void MCAL_EXTI_GPIO_DEINIT(void)                         ;
void MCAL_EXTI_GPIO_UPDATE(EXTI_PinConfig_t* EXTI_Config)  ;

/*<--------------------------------------------------------------------------------------------------------->*/


#endif /* INC_STM32_F103C6_EXTI_DRIVER_H_ */
