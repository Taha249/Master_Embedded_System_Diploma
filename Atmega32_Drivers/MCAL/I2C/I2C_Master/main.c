/*
 * I2C_Master.c
 *
 * Created: 1/6/2024 1:50:41 AM
 * Author : Taha
 */ 

#include <avr/io.h>
#include "I2C.h"


int main(void)
{
    unsigned char ch = 0;
    I2C_INIT(0x48);

    while (1)
    {
	    _delay_ms(500);

	    // Transmit Start Condition
	    I2C_START();
	    
	    // Transmit SLA + W(0)
	    I2C_WRITE(0b11010000 + 0);
	    while ((TWSR) != 0x18);  // Wait for SLA + W(0) transmission completion and ACK reception
	    
	    // Transmit Data
	    I2C_WRITE(ch++);
	    while ((TWSR) != 0x28);  // Wait for Data transmission completion and ACK reception
	    
	    // Transmit Stop condition
	    I2C_STOP();
    }
}

