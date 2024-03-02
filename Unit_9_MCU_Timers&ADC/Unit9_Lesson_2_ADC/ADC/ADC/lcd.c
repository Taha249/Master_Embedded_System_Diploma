/*
 * lcd.c
 *
 * created: 12/3/2023 8:26:25 am
 *  author: Taha
 */ 


#include <stdio.h>
#include "Inc/lcd.h"
#include "Inc/BIT_MATH.h"

void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

static void LCD_KICK(void)
{
	SetBit(LCD_CONFIGE_PORT,LCD_E_PIN);
	_delay_us(2);
	ClearBit(LCD_CONFIGE_PORT,LCD_E_PIN);
	_delay_us(2);
}


static void LCD_IS_BUSY(void)
{

	LCD_DATA_DIR = 0x00;
	ClearBit(LCD_CONFIGE_PORT,LCD_RS_PIN);
	SetBit(LCD_CONFIGE_PORT,LCD_RW_PIN);
	LCD_KICK();
	LCD_DATA_DIR = 0xFF;
}


void LCD_INIT(void)
{
	
	LCD_CONFIGE_DIR |= (1<<LCD_RS_PIN) | (1<<LCD_RW_PIN) | (1<<LCD_E_PIN);
	LCD_CONFIGE_PORT &= ~((1<<LCD_RS_PIN) | (1<<LCD_RW_PIN) | (1<<LCD_E_PIN));
	LCD_DATA_DIR = 0xff;
	
	#if LCD_MODE == EIGHT_BIT_MODE
	
	_delay_ms(40);
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	
	#elif LCD_MODE == FOUR_BIT_MODE
	
	#endif
	
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_BLINK);
}


void LCD_WRITE_COMMAND(unsigned char command)
{
	LCD_IS_BUSY();
	#if LCD_MODE == EIGHT_BIT_MODE
	
	ClearBit(LCD_CONFIGE_PORT,LCD_RS_PIN);
	ClearBit(LCD_CONFIGE_PORT,LCD_RW_PIN);
	LCD_DATA_PORT = command;
	LCD_KICK();
	
	#elif LCD_MODE == FOUR_BIT_MODE
	
	#endif
}


void LCD_WRITE_CHAR(unsigned char data)
{
	LCD_IS_BUSY();
	
	SetBit(LCD_CONFIGE_PORT,LCD_RS_PIN);
	ClearBit(LCD_CONFIGE_PORT,LCD_RW_PIN);
	LCD_DATA_PORT = data;
	LCD_KICK();
}

void LCD_WRITE_STRING(const char* data)
{
	unsigned char i =0 , count= 0;
	while(data[i] != '\0')
	{
		count++;
		LCD_WRITE_CHAR(data[i]);
		i++;
		if(count == 16)
		{
			LCD_GO_TO_XY(1,0);
		}
		else if(count == 32 || count == 33)
		{
			LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
			LCD_GO_TO_XY(0,0);
			count = 0;
		}
	}
}

void LCD_GO_TO_XY(unsigned char line,unsigned char column)
{
	if(line == 0)
	{
		if(column>=0 && column <16)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+column);
		}
	}
	else if(line == 1 )
	{
		if(column>=0 && column <16)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+column);
		}
	}
	
}


void LCD_WRITE_NUMBER(int number)
{
	char str[7];
	sprintf(str,"%d",number);
	LCD_WRITE_STRING(str);
}

void LCD_WRITE_REAL_NUMBER(double real_number)
{
	char str[16];
	
	char* sign = (real_number<0) ? "-" : "";
	float val = (real_number<0) ? -real_number : real_number;
	
	int num = val;
	float dec = val - num;
	int finalDec = dec*10000;
	
	sprintf(str,"%s%d.%04d",sign,num,finalDec);
	LCD_WRITE_STRING(str);
}