/*
 * ca.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
//Define states
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//declare state function CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

//STATE pointer to function
extern void (*CA_state)();

#endif /* CA_H_ */
