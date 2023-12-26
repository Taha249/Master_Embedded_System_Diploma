/*
 * KeyPad.h
 *
 * Created: 11/6/2021 2:15:42 PM
 *  Author: user
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define r0 DIO_ChannelD0
#define r1 DIO_ChannelD1
#define r2 DIO_ChannelC0
#define r3 DIO_ChannelD3

#define c0 DIO_ChannelD4
#define c1 DIO_ChannelD5
#define c2 DIO_ChannelC1
#define c3 DIO_ChannelD7

Uint8 GetKey(void);

#endif /* KEYPAD_H_ */