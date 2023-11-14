/*
 * Alarm_monitor.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"
#include "Platform_Types.h"
#include "stdint.h"
#include "stdio.h"


extern void (*PD_alarm_monitor_state)();

enum {

	PD_alarmOFF,
	PD_alarmON,
	PD_waiting
}PD_state_id;

STATE_define(PD_alarmOFF);
STATE_define(PD_alarmON);
STATE_define(PD_waiting);

void Alarm_monitor_init();


#endif /* ALARM_MONITOR_H_ */
