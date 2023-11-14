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
#include "GPIO.h"
//Automatic state function generated
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_


void startAlarm();
void stopAlarm();
void highpressure_detected();

#endif /* STATE_H_ */
