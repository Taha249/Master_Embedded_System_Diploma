/*
 * S_SPI.c
 *
 * Created: 12/30/2023 11:28:23 PM
 *  Author: Taha
 */ 


#include "S_SPI.h"

void SPI_Init(char state){
	switch(state){
		case 'M':
		SPI_DDR |= (1<<MOSI)|(1<<SCK)|(1<<SS);
		SPI_DDR &=~ (1<<MISO);
		SPCR = (1<<MSTR)|(1<<SPE);
		break;
		case 'S':
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