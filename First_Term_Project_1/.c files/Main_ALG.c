/*
 * Main_ALG.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */


#include "Main_ALG.h"
#include "stdio.h"
#include "stdlib.h"
#include "GPIO.h"
#include "state.h"

//PD->Pressure Detection
//Set the variables
static int PD_threshold = 20 ;
static int PD_pVal = 0 ; //set_pressure_val

void (*PD_Main_ALG_state)();

STATE_define(PD_highpressure_detected)
{
	//State_name
	Main_ALG_status = PD_highpressure_detected;
;	//State_action
	PD_pVal = 0 ;
 	//Event_check
	(PD_pVal <= PD_threshold)? (PD_Main_ALG_state(PD_pVal)) : (PD_Main_ALG_state(PD_highpressure_detected));
}
