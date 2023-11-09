/*
 * main.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */
#include "CA.h"

void setup()
{
	//initialize all the drivers
	//initialize IRQ...
	//initialize HAL US_Driver DC_Driver
	//initialize BLOCK
	//Set states pointers for each block
	CA_state = STATE (CA_waiting);


}

int main()
{
	setup();
	while(1)
	{
		//call state for each block
		CA_state();
	}
}
