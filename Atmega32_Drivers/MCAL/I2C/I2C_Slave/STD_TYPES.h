/*
 * STD_TYPES.h
 *
 * Created: 1/6/2024 12:58:54 AM
 *  Author: Taha
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// Define constants for HIGH and LOW values
#define HIGH 1
#define LOW  0

// Define unsigned integer types with different sizes
typedef unsigned char Uint8t;      // Range: 0 to 255
typedef unsigned short int Uint16t;
typedef unsigned long int Uint32t;

// Define signed integer types with different sizes
typedef signed char Int8t;         // Range: -127 to 127
typedef signed short int Int16t;
typedef signed long int Int32t;

// Define floating-point types
typedef float Fint32t;
typedef double Dint64t;

// Define an enumeration for standard logic levels
typedef enum
{
	STD_LOW = 0,   // Standard logic low
	STD_HIGH = 1   // Standard logic high
} STD_levelType;




#endif /* STD_TYPES_H_ */