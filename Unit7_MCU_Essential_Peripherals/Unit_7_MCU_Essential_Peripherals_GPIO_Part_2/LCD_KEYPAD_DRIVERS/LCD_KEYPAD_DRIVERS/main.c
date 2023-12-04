/*
 * LCD_KEYPAD_DRIVERS.c
 *
 * Created: 12/3/2023 8:25:29 AM
 * Author : Taha
 */ 

#include <avr/io.h>
#include "LCD_Driver/lcd.h"
#include "KEYPAD_Driver/keypad.h"


int main()
{
	LCD_INIT();
	Keypad_init();
	_delay_ms(50);
	unsigned char key_pressed;
	while(1){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
			case 'A':
			break;
			case '?':
			LCD_clear_screen();
			break;
			default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}
	}
}

