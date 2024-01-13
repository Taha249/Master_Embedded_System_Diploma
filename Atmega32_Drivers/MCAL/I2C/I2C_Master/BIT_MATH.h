/*
 * BIT_MATH.h
 *
 * Created: 1/6/2024 12:53:23 AM
 *  Author: Taha
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG, BIT)    REG |= (1 << BIT)        // Set the specified bit (BIT) in the register (REG).
#define CLR_BIT(REG, BIT)    REG &= ~(1 << BIT)       // Clear the specified bit (BIT) in the register (REG).
#define GET_BIT(REG, BIT)    ((REG >> BIT) & 1)       // Retrieve the value of the specified bit (BIT) from the register (REG).
#define TGL_BIT(REG, BIT)    REG ^= (1 << BIT)        // Toggle the specified bit (BIT) in the register (REG).
#define Get_LOW_Nibble(REG)  REG & 0x0F               // Retrieve the low nibble (4 bits) from the register (REG).
#define Get_HIGH_Nibble(REG) (REG >> 4) & 0b00001111  // Retrieve the high nibble (4 bits) from the register (REG).
#define GET_PORT(REG)        REG & 0xFF               // Retrieve the high nibble (4 bits) from the register (REG).
#define TGL_PORT(REG)        REG ^= 0xFF              // Toggle all bits in the lower byte (8 bits) of the register (REG).



#endif /* BIT_MATH_H_ */