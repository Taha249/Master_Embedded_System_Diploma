/*
 * Alarm_actuator_driver.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */

#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

#include "GPIO.h"
#include "state.h"
#include "Platform_Types.h"
#include "stdint.h"
#include "stdio.h"



void startAlarm();
void stopAlarm();

extern void (*PD_Alarm_actuator_state)();

enum {
	AlarmON,
	AlarmOFF
}Alarm_actuator_state;


STATE_define(AlarmON);
STATE_define(AlarmOFF);


void Alarm_actuator_driver_init();


#endif /* ALARM_ACTUATOR_DRIVER_H_ */
