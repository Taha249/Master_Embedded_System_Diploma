/*
 * US.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */

#ifndef US_H_
#define US_H_
#include "state.h"
//Define states
enum{
	US_busy,
}US_state_id;

//declare state function US
STATE_define(US_busy);


void US_init();
//STATE pointer to function
extern void (*US_state)();

#endif /* US_H_ */
