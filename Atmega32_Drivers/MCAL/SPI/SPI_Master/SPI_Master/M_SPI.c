/*
 * M_SPI.c
 *
 * Created: 12/30/2023 11:19:31 PM
 *  Author: Taha
 */ 


#include "M_SPI.h"

void SPI_Init(SPI_InitOptions options){
	switch(options.state){
		case Master:
		SPI_DDR |= (1<<MOSI)|(1<<SCK)|(1<<SS);
		SPI_DDR &=~ (1<<MISO);
		//SPCR = (1<<MSTR)|(1<<SPE);
		//SPI->MySPCR = (1<<MSTR)|(1<<SPE);
		//SPI->MySPCR.MyMSTR = 1;
		//SPI->MySPCR.MySPE = 1;
		//SPI->MySPCR.Bits.MyMSTR = 1;
		//SPI->MySPCR.Bits.MySPE = 1;
		SPI->MySPCR.AllReg = 0x50;
		break;
		case Slave:
		SPI_DDR &=~ (1<<MOSI)|(1<<SCK)|(1<<SS);//input pins
		SPI_DDR |= (1<<MISO);//output pins
		SPCR = (1<<SPE);
		break;
	}
}
unsigned char SPI_TxRx(unsigned char data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));//waiting the flag to be 1
	return SPDR;
}