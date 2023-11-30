/*
 * Unit7_Lesson1_Section_Task_3.c
 *
 * Created: 11/30/2023 4:00:22 PM
 * Author : Taha
 */ 

#define F_CPU 8000000UL
#include "DIO_HW.h"
#include <util/delay.h>
#include "BIT_MATH.h"


int main(void)
{
	
	//DDRD 0 >> input pulldown switch
	ClearBit(DDRD_Reg, 0);
	ClearBit(PORTD_Reg, 0);
	//PORTD 4,5
	SetBit(DDRD_Reg, 4);
	SetBit(DDRD_Reg, 5);
	
	while (1)
	{
		if(GetBit(PIND_Reg, 0) == 1){
			SetBit(PORTD_Reg, 4);
			SetBit(PORTD_Reg, 5);
			_delay_ms(1000);
			ClearBit(PORTD_Reg, 4);
			ClearBit(PORTD_Reg, 5);
			while(GetBit(PORTD_Reg, 0) == 1);
		}
	}
}