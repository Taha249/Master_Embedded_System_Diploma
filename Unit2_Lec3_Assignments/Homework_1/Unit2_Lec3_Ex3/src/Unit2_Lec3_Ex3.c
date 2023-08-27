/*
 ============================================================================
 Name        : Unit2_Lec3_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to Add Two Integers
 ============================================================================
 */

#include <stdio.h>

int main() {
    int num1, num2, sum;

    printf("Enter the first integer: ");
    fflush(stdout);
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    fflush(stdout);
    scanf("%d", &num2);
    sum = num1 + num2;
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);
    return 0;
}
