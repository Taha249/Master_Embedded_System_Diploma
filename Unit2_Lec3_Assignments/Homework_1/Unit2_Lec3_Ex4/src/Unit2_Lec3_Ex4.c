/*
 ============================================================================
 Name        : Unit2_Lec3_Ex4.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to Multiply two Floating Point Numbers
 ============================================================================
 */

#include <stdio.h>

int main() {
    float num1, num2, multip;
    printf("Enter two numbers: ");
    fflush(stdout);
    scanf("%f %f", &num1, &num2);
    multip = num1 * num2;
    printf("multip: %.6f\n",multip);
    return 0;
}
