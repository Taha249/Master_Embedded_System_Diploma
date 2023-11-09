/*
 * state.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Taha
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
//Automatic state function generated
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_

//states connection
void US_Set_distance(int d);
void DC_motor(int s);

#endif /* STATE_H_ */
