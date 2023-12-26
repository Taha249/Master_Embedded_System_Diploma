/*
 * DIO_layerarc.c
 *
 * Created: 10/30/2021 1:45:05 PM
 * Author : Taha
 */ 

#include "DIO.h"

int main(void)
{
    DIO_Init();
	DIO_WriteChannel(DIO_ChannelA2,STD_High);
	DIO_WriteChannel(DIO_ChannelA3,STD_High);
	DIO_WriteChannel(DIO_ChannelD3,STD_High);
    while (1) 
    {
    }
}

