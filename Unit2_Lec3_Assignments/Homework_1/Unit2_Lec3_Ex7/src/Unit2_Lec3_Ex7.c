/*
 ============================================================================
 Name        : Unit2_Lec3_Ex7.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description :Write Source Code to Swap Two Numbers without temp variable.
 ============================================================================
 */

#include <stdio.h>

int main() {
    float a, b;
    printf("Enter value of a: ");
    fflush(stdout);
    scanf("%f", &a);
    printf("Enter value of b: ");
    fflush(stdout);
    scanf("%f", &b);
    printf("Before swapping, value of a,b = %f\n,%f\n",a,b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("\nAfter swapping, value of a,b = %f\n,%f\n",a,b);
    return 0;
}
