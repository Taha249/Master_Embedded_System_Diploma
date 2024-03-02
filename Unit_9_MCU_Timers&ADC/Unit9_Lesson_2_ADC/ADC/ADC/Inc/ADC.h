/*
 * ADC.h
 *
 * Created: 3/2/2024 1:53:33 PM
 *  Author: Taha
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "DIO.h"
#include "LCD.h"

void ADC_Init(void);
unsigned short ADC_Read(unsigned char channel);



#endif /* ADC_H_ */