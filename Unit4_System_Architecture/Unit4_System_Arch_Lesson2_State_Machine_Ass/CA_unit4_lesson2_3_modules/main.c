/*
 * main.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */
#include "CA.h"
#include "US.h"
#include "DC.h"


void setup()
{
	//initialize all the drivers
	//initialize IRQ...
	//initialize HAL US_Driver DC_Driver
	//initialize BLOCK
	US_init();
	DC_init();
	//Set states pointers for each block
	CA_state = STATE (CA_waiting);
	US_state = STATE (US_busy);
	DC_state = STATE (DC_ideal);


}

int main()
{
	setup();
	while(1)
	{
		//call state for each block
		US_state();
		CA_state();
		DC_state();
	}
}
