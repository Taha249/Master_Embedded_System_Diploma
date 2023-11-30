/*
 * Unit7_Lesson1_Section_Task_1.c
 *
 * Created: 11/29/2023 1:37:40 AM
 * Author : Taha
 */ 


#define F_CPU 8000000UL
#include "DIO_HW.h"
#include <util/delay.h>
#include "BIT_MATH.h"



int main(void)
{
	DDRA_Reg = 0xFFFFFFFF ;
	
	while (1)
	{
		int8 i ;
		
		//Turn ON all LEDS sequentially
		for(i=0;i<8;i++){
			SetBit(PORTA_Reg,i);
			_delay_ms(300);
		}
		
		//Turn OFF all LEDS sequentially
		for(i=7;i>=0;i--){
			ClearBit(PORTA_Reg,i);
			_delay_ms(300);
		}
		
		_delay_ms(500);
	}
	
	return 0;
}

