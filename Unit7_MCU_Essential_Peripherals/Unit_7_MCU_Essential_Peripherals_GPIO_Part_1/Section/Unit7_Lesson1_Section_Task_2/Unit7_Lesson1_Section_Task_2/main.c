/*
 * Unit7_Lesson1_Section_Task_2.c
 *
 * Created: 11/29/2023 1:54:01 AM
 * Author : Taha
 */ 

#define F_CPU 8000000UL
#include "DIO_HW.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#


int main(void)
{
	DDRA_Reg = 0xFFFFFFFF ;
	ClearBit(DDRD_Reg, 0);
	Uint8 state = 0 ;
	while (1)
	{
		if ( GetBit(PIND_Reg,0) == 1)
		{		
			
			if (state <= 7)
			{
				SetBit(PORTA_Reg,state);
				state++;
			}
			else
			{
				
				PORTA_Reg = 0;
				state = 0;
			}					
			while( GetBit(PIND_Reg,0) == 1 );			
		}
		_delay_ms(100);
	}
	
	return 0;
}

