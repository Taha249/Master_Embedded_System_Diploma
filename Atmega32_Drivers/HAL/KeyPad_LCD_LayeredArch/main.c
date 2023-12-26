/*
 * KeyPad_LCD_LayeredArch_E25.c
 *
 * Created: 11/6/2021 2:13:30 PM
 * Author : user
 */ 

#include "LCD.h"
#include "KeyPad.h"

int main(void)
{
	DIO_Init();
	LCD_Init();
	Uint8 data = 0;
    while (1) 
    {
		data = GetKey();
		if(data != 0){
			LCD_Char(data);
		}	
    }
}

