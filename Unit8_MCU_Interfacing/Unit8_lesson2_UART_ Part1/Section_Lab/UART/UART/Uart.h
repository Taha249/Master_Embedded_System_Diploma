/*
 * Uart.h
 *
 * Created: 12/25/2023 3:48:35 PM
 *  Author: Taha
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL

#define BaudRate 9600

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU/(BaudRate*16UL))-1) // Double
#else
#define MyUBRR ((F_CPU/(BaudRate*8UL))-1) // Normal
#endif


void Uart_Init();
void Uart_Transmit(char data);
char Uart_Receive();
void Uart_TransmitString(char * string);




#endif /* UART_H_ */