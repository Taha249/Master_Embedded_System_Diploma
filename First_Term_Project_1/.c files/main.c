/*
 * main.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */


#include "stdint.h"
#include "stdio.h"
#include "GPIO.h"
#include "Pressure_sensor_driver.h"
#include "Main_ALG.h"
#include "Alarm_monitor.h"
#include "Alarm_actuator_driver.h"
#include "Platform_Types.h"
#include "state.h"


int threshold = 20;

void setup()
{
	GPIO_INITIALIZATION();
	Pressure_Sensor_driver_init();
	PD_Pressure_Sensor_driver_state = STATE(PD_reading);
	PD_alarm_monitor_state = STATE(PD_alarmOFF) ;
	PD_Alarm_actuator_state = STATE(AlarmOFF);

}
int main (){
	setup();

	while (1)
	{
		PD_Pressure_Sensor_driver_state();
		PD_alarm_monitor_state();
		PD_Alarm_actuator_state();
		PD_alarm_monitor_state();
		PD_Alarm_actuator_state();
	}
}

