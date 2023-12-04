/*
 * calculator.c
 *
 * created: 12/4/2023 2:27:42 am
 * author : Taha
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "keypad.h"

int main(void)
{
	LCD_INIT();
	KEYPAD_INIT();
	_delay_ms(200);
	char button_push = 0, oprand = 0;
	int num_1 = 0 , num_2= 0 ,res = 0;
	LCD_WRITE_STRING("Learn_In_Depth..");
	_delay_ms(1000);
	LCD_clear_screen();
	LCD_WRITE_STRING(" Eng.Taha Hamed");
	_delay_ms(2000);
	LCD_clear_screen();
	LCD_WRITE_STRING(" ==Calculator==");
	_delay_ms(2000);
    LCD_clear_screen();
	while (1)
	{
		
		button_push = KEYPAD_GET_KEY();
		
		if (button_push != '?')
		{
			
			LCD_WRITE_CHAR(button_push);
			if (button_push == '+' || button_push == '-' || button_push == '*' || button_push == '/' )
			{
				oprand = button_push;
			}
			if((button_push>='0' && button_push<='9') && (oprand==0))
			{
				num_1 += (button_push-48);
				num_1 *= 10;
			}
			if((button_push>='0' && button_push<='9') && (oprand!=0))
			{
				num_2 += (button_push-48);
				num_2 *= 10;
			}
			if (button_push == '=')
			{
				switch(oprand)
				{
					case '+':res = (num_1/10) + (num_2/10); break;
					case '-':res = (num_1/10) - (num_2/10); break;
					case '*':res = (num_1/10) * (num_2/10); break;
					case '/':res = (num_1/10) / (num_2/10); break;
				}
				
				LCD_GO_TO_XY(1,0);
				LCD_WRITE_NUMBER(res);
				while(button_push != '@')
				{
					button_push = KEYPAD_GET_KEY();
				}
				LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
				res=0 , num_1 = 0 ,num_2 = 0 , oprand = 0;
			}
		}
	}
}