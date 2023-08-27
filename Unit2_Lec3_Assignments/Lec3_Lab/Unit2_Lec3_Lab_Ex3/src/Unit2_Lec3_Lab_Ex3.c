/*
 ============================================================================
 Name        : Unit2_Lec3_Lab_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to calculate the summation of values between 1 and 99.
 ============================================================================
 */

#include <stdio.h>

int main() {
    int i, sum = 0;
    for (i = 1; i <= 99; i++) {
        sum += i;
    }
    printf("Sum of numbers between 1 and 99 is: %d", sum);
    return 0;
}
