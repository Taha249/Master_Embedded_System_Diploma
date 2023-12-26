/*
 * DIO_CFG.c
 *
 * Created: 10/30/2021 4:28:43 PM
 *  Author: Taha
 */ 
#include "DIO_CFG.h"
DIO_PinCfg PinInit[] = {
	//PORTA
	{Output,STD_High},
    {Output,STD_High},
	{Output,STD_High},
    {Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
		
	//PORTB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
		
	//PORTD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High}
	};
void DIO_Init()	{
	Uint8 count = DIO_ChannelA0;
	DIO_PortTypes Portx; 
	DIO_ChannelTypes BitNumber; 
	for (count=0;count<PINCOUNT;count++)
	{
		Portx = count/8;
		BitNumber = count%8;
		switch(Portx){
			case DIO_PortA:
			if(PinInit[count].PinDir == Output)
			{
				SetBit(DDRA_Reg,BitNumber);
			}
			else{
				ClearBit(DDRA_Reg,BitNumber);
			}
			break;
			case DIO_PortB:
			if(PinInit[count].PinDir == Output)
			{
				SetBit(DDRB_Reg,BitNumber);
			}
			else{
				ClearBit(DDRB_Reg,BitNumber);
			}
			break;
			case DIO_PortC:
			if(PinInit[count].PinDir == Output)
			{
				SetBit(DDRC_Reg,BitNumber);
			}
			else{
				ClearBit(DDRC_Reg,BitNumber);
			}
			break;
			case DIO_PortD:
			if(PinInit[count].PinDir == Output)
			{
				SetBit(DDRD_Reg,BitNumber);
			}
			else{
				ClearBit(DDRD_Reg,BitNumber);
			}
			break;
		}
	}
}