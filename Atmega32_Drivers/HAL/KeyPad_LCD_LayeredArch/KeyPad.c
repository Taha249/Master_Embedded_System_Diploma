/*
* KeyPad.c
*
* Created: 11/6/2021 2:15:55 PM
*  Author: user
*/

#include "KeyPad.h"

Uint8 KeyPadRows[4] = {r0,r1,r2,r3};
Uint8 KeyPadCols[4] = {c0,c1,c2,c3};
Uint8 KeyPad[4][4] = {{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'C','0','=','+'}};

Uint8 GetKey(void){
	for (Uint8 w=0;w<4;w++)//PORTD = 0b1111 1111
	{
		DIO_WriteChannel(KeyPadRows[w],STD_High);//output
		DIO_WriteChannel(KeyPadCols[w],STD_High);//input & enable pull up Res.
	}
	for (Uint8 i=0;i<4;i++)
	{
		DIO_WriteChannel(KeyPadRows[i],STD_Low);
		for (Uint8 j=0;j<4;j++)
		{
			if (DIO_ReadChannel(KeyPadCols[j]) == STD_Low)
			{
				while (DIO_ReadChannel(KeyPadCols[j]) == STD_Low);
				return KeyPad[i][j];
			}
		}
		DIO_WriteChannel(KeyPadRows[i],STD_High);
	}
	return STD_Low;
}