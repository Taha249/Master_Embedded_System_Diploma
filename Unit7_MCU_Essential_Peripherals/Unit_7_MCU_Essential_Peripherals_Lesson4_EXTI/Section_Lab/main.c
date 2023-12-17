/*
 * Unit7_Lesson4_Section_Lab.c
 *
 * Created: 12/18/2023 12:34:12 AM
 * Author : Taha
 */ 


#define F_CPU 10000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_Driver/lcd.h"
#include "KEYPAD_Driver/keypad.h"

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		LCD_INIT();
		LCD_WRITE_STRING("Learn_In_Depth..");
		_delay_ms(1000);
		LCD_clear_screen();
		LCD_WRITE_STRING(" Eng.Taha Hamed");
		_delay_ms(2000);
		LCD_clear_screen();

    }
}

