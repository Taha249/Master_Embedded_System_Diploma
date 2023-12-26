/*
 * DIO.h
 *
 * Created: 10/30/2021 3:39:26 PM
 *  Author: Taha
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"


 void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level);
 STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId);

#endif /* DIO_H_ */