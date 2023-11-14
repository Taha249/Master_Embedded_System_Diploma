/*
 * Pressure_Sensor_driver.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Taha
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include "state.h"
#include "Platform_Types.h"
#include "stdint.h"
#include "stdio.h"



extern void (*PD_Pressure_Sensor_driver_state)();

void Pressure_Sensor_driver_init();

enum {
	PD_reading,
	PD_waitting
}PD_Pressure_Sensor;

STATE_define(PD_reading);
STATE_define(PD_waiting);


#endif /* PRESSURE_SENSOR_DRIVER_H_ */
