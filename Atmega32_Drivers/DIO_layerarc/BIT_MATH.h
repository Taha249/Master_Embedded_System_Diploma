/*
 * BIT_MATH.h
 *
 * Created: 10/29/2021 4:16:05 PM
 *  Author: Taha
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define SetBit(Reg,BitNumber) (Reg |= (1<<BitNumber))
#define ClearBit(Reg,BitNumber) (Reg &=~ (1<<BitNumber))
#define ToggleBit(Reg,BitNumber) (Reg ^= (1<<BitNumber))
#define GetBit(Reg,BitNumber) ((Reg>>BitNumber)&1) 




#endif /* BIT_MATH_H_ */