/*
 * ca.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"
//Define states
enum{
	DC_ideal,
	DC_busy
}DC_state_id;

//declare state function DC
STATE_define(DC_ideal);
STATE_define(DC_busy);

void DC_init();

//STATE pointer to function
extern void (*DC_state)();

#endif /* DC_H_ */
