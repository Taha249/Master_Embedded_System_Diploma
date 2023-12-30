/*
* UART.c
*
* Created: 11/27/2021 3:50:01 PM
*  Author: user
*/
#include "UART.h"

void Uart_Init(){
	UCSRB = (1<<TXEN)|(1<<RXEN);//enable TX & RX
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);//8 BITS
	UBRRL = MyUBRR;
	UBRRH = MyUBRR >> 8;
}
void Uart_Transmit(char data){
	while (!(UCSRA & (1<<UDRE)));//waiting UDR to be empty
	UDR = data;
}
char Uart_Receive(){
	while (!(UCSRA & (1<<RXC)));//waiting receive to complete
	return UDR;
}
void Uart_TransmitString(char * string){
	unsigned char i = 0;
	while(string[i] != '\0'){
		Uart_Transmit(string[i]);
		i++;
	}
}