/*
 * Pressure_Sensor_driver.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */


#include "state.h"
#include "GPIO.h"
#include "Pressure_sensor_driver.h"

static int pVal = 0 ;

void (*PD_Pressure_Sensor_driver_state)();

void Pressure_Sensor_driver_init()
{
	//printf("Pressure_Sensor_driver_init");
}

STATE_define(PD_reading)
{
	PD_Pressure_Sensor = PD_reading ;
	Delay(1000000);
	PD_Pressure_Sensor_driver_state = STATE(PD_reading);

}

STATE_define(PD_waitting)
{
	PD_Pressure_Sensor = PD_waitting ;
	pVal = getPressureVal();
	getPressureVal(pVal);
	PD_Pressure_Sensor_driver_state = STATE(PD_waiting);
}
