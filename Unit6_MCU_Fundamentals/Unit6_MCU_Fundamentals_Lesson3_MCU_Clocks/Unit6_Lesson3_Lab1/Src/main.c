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

typedef volatile unsigned int vuint32_t;
#include <stdint.h>
//register address
#define RCC_BASE      0x40021000
#define GPIOA_BASE    0x40010800
#define RCC_APB2ENR   *(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH     *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define RCC_CFGR   *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR   *(volatile uint32_t *)(RCC_BASE + 0x0)





//bit fields
#define RCC_IOPAEN   (1<<2)
#define GPIOA13      (1<<13)

typedef union {
	vuint32_t        all_fileds;
	struct{
		vuint32_t    reserved:13;
		vuint32_t    P_13:1;

	} Pin;
} R_ODR_t;

volatile R_ODR_t*  R_ODR =  (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);


int main(void)
{
	//	Bits 21:18 PLLMUL: PLL multiplication factor
	//	These bits are written by software to define the PLL multiplication factor. These bits can be
	//	written only when PLL is disabled.
	//	Caution: The PLL output frequency must not exceed 72 MHz.
	//	0000: PLL input clock x 2
	//	0001: PLL input clock x 3
	//	0010: PLL input clock x 4
	//	0011: PLL input clock x 5
	//	0100: PLL input clock x 6
	//	0101: PLL input clock x 7
	//	0110: PLL input clock x 8
	RCC_CFGR |= (0b0110 << 18);


	//	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	//	Set and cleared by software to control the division factor of the APB high-speed clock
	//	(PCLK2).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16

	RCC_CFGR |= (0b101 << 11);

	//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	//	Set and cleared by software to control the division factor of the APB low-speed clock
	//	(PCLK1).
	//	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16

	RCC_CFGR |= (0b100 << 8);

	//    Bits 1:0 SW: System clock switch
	//Set and cleared by software to select SYSCLK source.
	//Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	//failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	//System is enabled).
	//00: HSI selected as system clock
	//01: HSE selected as system clock
	//10: PLL selected as system clock
	//11: not allowed

	RCC_CFGR |= (0b10 << 0);

	//	Bit 24 PLLON: PLL enable
	//	Set and cleared by software to enable PLL.
	//	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	//	PLL clock is used as system clock or is selected to become the system clock.
	//	0: PLL OFF
	//	1: PLL ON

	RCC_CR |= 1<<24;



	RCC_APB2ENR  |= RCC_IOPAEN;
	GPIOA_CRH    &= 0xFF0FFFFF;
	GPIOA_CRH    |= 0x00200000;

	while(1)
	{
		R_ODR->Pin.P_13 = 1;
		for(int i =0; i<5000; i++); //arbitrary delay
		R_ODR->Pin.P_13 = 0;
		for(int i =0; i<5000; i++); //arbitrary delay

	}

	return 0;
}
