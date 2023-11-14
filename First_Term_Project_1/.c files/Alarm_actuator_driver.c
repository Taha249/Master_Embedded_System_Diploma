/*
 * Alarm_actuator_driver.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */


#include "Alarm_actuator_driver.h"
#include "GPIO.h"
#include "state.h"

void Alarm_monitor_init()
{
	//printf("Alarm_monitor_init");
}

void (*PD_Alarm_actuator_state)();

void startAlarm()
{
	PD_Alarm_actuator_state = STATE(AlarmON);

}

void stopAlarm()
{
	PD_Alarm_actuator_state = STATE(AlarmOFF);
}

STATE_define(AlarmON)
{
	//State_name
	Alarm_actuator_state = AlarmON ;
	Set_Alarm_actuator(0);
}

STATE_define(AlarmOFF)
{
	Alarm_actuator_state = AlarmOFF ;
		Set_Alarm_actuator(1);
}
