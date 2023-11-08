/*
 * lifo.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Taha
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

typedef struct {
	unsigned int length ; //represent total length of LIFO buffer
	unsigned int count ; //represent current number of items in LIFO buffer
	unsigned int* base ; //represent a pointer to a base buffer
	unsigned int* head ; //represent to a pointer to the head of the buffer
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null,
}LIFO_status;

LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf, unsigned int item); //add an item to the LIFO buffer
LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf, unsigned int* item); // retrieve an item from the LIFO buffer
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length); //initialize the LIFO buffer

#endif /* LIFO_H_ */
