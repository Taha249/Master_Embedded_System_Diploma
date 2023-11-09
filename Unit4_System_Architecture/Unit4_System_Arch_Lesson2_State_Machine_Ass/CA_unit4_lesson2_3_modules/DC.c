/*
 * DC.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */


#include "stdio.h"
#include "stdlib.h"

#include "DC.h"
//variables
int DC_speed = 0;

//STATE pointer to function
void (*DC_state)();

void DC_init()
{
	//init PWM
	printf("DC_init \n");
}

void DC_motor(int s)
{
	DC_speed = s ;
	DC_state = STATE(DC_busy);
	printf("CA --------speed=%d--------> DC \n", DC_speed);


}
STATE_define(DC_ideal)
{
	//state_name
	DC_state_id = DC_ideal ;

	//state_action
	//call PWM to make speed = DC_speed
	//cd_motor (DC_speed)
	//DC_Get_distance (DC_distance)

	printf("DC_ideal State : speed=%d \n", DC_speed);
}

STATE_define(DC_busy)
{
	//state_name
	DC_state_id = DC_busy ;

	//state_action
	DC_speed = 30;

	//cd_motor (DC_speed)
	DC_state = STATE(DC_ideal);


	printf("DC_ideal State : speed=%d \n", DC_speed);



}



