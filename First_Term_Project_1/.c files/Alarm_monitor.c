/*
 * Alarm_monitor.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */


#include "Alarm_monitor.h"
#include "state.h"
#include "GPIO.h"

void (*PD_alarm_monitor_state)();



void highpressure_detected()
{
	PD_alarm_monitor_state = STATE(PD_alarmON);
}

STATE_define(PD_alarmOFF)
{
	PD_state_id = PD_alarmOFF ; //State_name
	//State_actions
	stopAlarm();
	PD_alarm_monitor_state = STATE(PD_alarmOFF) ;

}
STATE_define(PD_alarmON)
{
	//State_name
	PD_state_id = PD_alarmON ;
	//State_action
	startAlarm();
	PD_alarm_monitor_state = STATE(PD_alarmON) ;
}
STATE_define(PD_waiting)
{
	//State_name
	PD_state_id = PD_waiting;
	//State_action
	Delay(60000);
	stopAlarm();
	PD_alarm_monitor_state = STATE(PD_waiting);


}
