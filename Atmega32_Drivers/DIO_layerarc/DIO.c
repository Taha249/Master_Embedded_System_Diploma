/*
* DIO.c
*
* Created: 10/30/2021 3:40:18 PM
*  Author: Taha
*/
#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNumber = channelId%8;
	switch(Portx)
	{
		case DIO_PortA:
		if(level == STD_High)
		{
			SetBit(PORTA_Reg,BitNumber);
		}
		else
		{
			ClearBit(PORTA_Reg,BitNumber);
		}
		break;
		case DIO_PortB:
		if(level == STD_High)
		{
			SetBit(PORTB_Reg,BitNumber);
		}
		else
		{
			ClearBit(PORTB_Reg,BitNumber);
		}
		break;
		case DIO_PortC:
		if(level == STD_High)
		{
			SetBit(PORTC_Reg,BitNumber);
		}
		else
		{
			ClearBit(PORTC_Reg,BitNumber);
		}
		break;
		case DIO_PortD:
		if(level == STD_High)
		{
			SetBit(PORTD_Reg,BitNumber);
		}
		else
		{
			ClearBit(PORTD_Reg,BitNumber);
		}
		break;
	}
}

STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNumber = channelId%8;
	STD_LevelTypes BitValue = STD_Low;
	switch(Portx){
		case DIO_PortA:
		BitValue = GetBit(PINA_Reg,BitNumber);
		break;
		case DIO_PortB:
		BitValue = GetBit(PINB_Reg,BitNumber);
		break;
		case DIO_PortC:
		BitValue = GetBit(PINC_Reg,BitNumber);
		break;
		case DIO_PortD:
		BitValue = GetBit(PIND_Reg,BitNumber);
		break;
	}
	return BitValue;
}