/*
 * lifo.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Taha
 */


#include "lifo.h"

// Function to add an item to the LIFO buffer
LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf, unsigned int item)
{
    // Check if LIFO buffer is valid
    if (!lifo_buf->base || !lifo_buf->head)
        return LIFO_Null; // Return LIFO_Null if buffer is not valid

    // Check if LIFO buffer is full
    if (lifo_buf->count == lifo_buf->length)
        return LIFO_full; // Return LIFO_full if buffer is full

    // Add value (push) to the LIFO buffer
    *(lifo_buf->head) = item;
    lifo_buf->head++;
    lifo_buf->count++;

    return LIFO_no_error; // Return LIFO_no_error to indicate successful addition
}

// Function to retrieve an item from the LIFO buffer
LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf, unsigned int* item)
{
    // Check if LIFO buffer is valid
    if (!lifo_buf->base || !lifo_buf->head)
        return LIFO_Null; // Return LIFO_Null if buffer is not valid

    // Check if LIFO buffer is empty
    if (lifo_buf->count == 0)
        return LIFO_empty; // Return LIFO_empty if buffer is empty

    // Retrieve item (pop) from the LIFO buffer
    lifo_buf->head--;
    *item = *(lifo_buf->head);
    lifo_buf->count--;

    return LIFO_no_error; // Return LIFO_no_error to indicate successful retrieval
}

// Function to initialize the LIFO buffer
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length)
{
    // Check if buffer pointer is NULL
    if (buf == NULL)
        return LIFO_Null; // Return LIFO_Null if buffer pointer is NULL

    // Initialize the LIFO buffer
    lifo_buf->base = buf;
    lifo_buf->head = buf;
    lifo_buf->length = length;
    lifo_buf->count = 0;

    return LIFO_no_error;
}