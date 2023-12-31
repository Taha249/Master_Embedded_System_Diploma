/*
 * S_SPI.h
 *
 * Created: 12/30/2023 11:28:38 PM
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
void SPI_Init(char state);
unsigned char SPI_TxRx(unsigned char data);



#endif /* S_SPI_H_ */