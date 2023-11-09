/*
 * US.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */


#include "stdio.h"
#include "stdlib.h"

#include "US.h"
//variables
int US_distance = 0;

//STATE pointer to function
void (*US_state)();



void US_init()
{
	//init US_Driver
	printf("US_init \n");

}
STATE_define(US_busy)
{
	//state_name
	US_state_id = US_busy ;

	//State_action
	printf("US_waiting State : distance=%d ", US_distance);
	US_Set_distance(US_distance);
	US_state = STATE(US_busy);
}




