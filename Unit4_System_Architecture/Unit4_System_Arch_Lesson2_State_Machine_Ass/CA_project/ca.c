/*
 * ca.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */


#include "CA.h"
#include "stdio.h"
#include "stdlib.h"
//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

//STATE pointer to function
void (*CA_state)();
int US_Get_distance_random(int l, int r, int count);

STATE_define(CA_waiting)
{
	//state_name
	CA_state_id = CA_waiting ;

	//state_action
	CA_speed = 0;

	//cd_motor (CA_speed)


	//event_check
	//US_Get_distance (CA_distance)
	CA_distance = US_Get_distance_random(45, 55, 1);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_waiting State : distance=%d speed=%d", CA_distance, CA_speed);
}

STATE_define(CA_driving)
{
	//state_name
	CA_state_id = CA_driving ;

	//state_action
	CA_speed = 30;

	//cd_motor (CA_speed)


	//event_check
	//US_Get_distance (CA_distance)
	CA_distance = US_Get_distance_random(45, 55, 1);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_driving State : distance=%d speed=%d", CA_distance, CA_speed);

}

int US_Get_distance_random(int l, int r, int count) // @suppress("No return")
{
		//This will generate random number in range l and r
		int i;
		for(i=0; i<count; i++)
		{
			int rand_num= (rand() % (r - l + 1)) + l;
			return rand_num;
		}

}




