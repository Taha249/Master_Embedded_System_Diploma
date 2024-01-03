/*
 * S_SPI.h
 *
 * Created: 12/30/2023 11:19:48 PM
 *  Author: Taha
 */ 


#ifndef S_SPI_H_
#define S_SPI_H_

#include <avr/io.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define SPI_PORT PORTB
#define SPI_DDR DDRB

#define Slave_Enable() (SPI_PORT &=~ (1<<SS))
#define Slave_Disable() (SPI_PORT |= (1<<SS))

typedef enum{
	Slave=0,
	Master
}SPI_StateTypes;

typedef struct
{
	SPI_StateTypes state;
}SPI_InitOptions;

typedef struct{
	unsigned char MySPR:2;
	unsigned char MyCPHA:1;
	unsigned char MyCPOL:1;
	unsigned char MyMSTR:1;
	unsigned char MyDORD:1;
	unsigned char MySPE:1;
	unsigned char MySPIE:1;
}SPI_MySPCRBits;

typedef union{
	unsigned char AllReg;
	SPI_MySPCRBits Bits;
}SPI_MySPCRType;

typedef struct
{
	SPI_MySPCRType MySPCR;
	unsigned char MySPSR;
	unsigned char MySPDR;
}SPI_Reg;

#define SPI ((volatile SPI_Reg *)0x2D)


void SPI_Init(SPI_InitOptions options);
unsigned char SPI_TxRx(unsigned char data);



#endif /* S_SPI_H_ */