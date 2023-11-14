/*
 * Main_ALG.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */

#ifndef MAIN_ALG_H_
#define MAIN_ALG_H_

#include "state.h"
#include "Platform_Types.h"
#include "stdint.h"
#include "stdio.h"


//Define all the states
extern void (*PD_Main_ALG_state)();

enum {
	PD_highpressure_detected,
}Main_ALG_status;

//Declare the state functions
STATE_define(PD_highpressure_detected);


#endif /* MAIN_ALG_H_ */
