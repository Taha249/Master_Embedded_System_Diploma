/*
 ============================================================================
 Name        : Unit2_Lec3_Ex6.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write Source Code to Swap Two Numbers
 ============================================================================
 */

#include <stdio.h>

int main() {
    float a, b, swap;
    printf("Enter value of a: ");
    fflush(stdout);
    scanf("%f", &a);
    printf("Enter value of b: ");
    fflush(stdout);
    scanf("%f", &b);
    printf("Before swapping, value of a,b = %f\n,%f\n",a,b);
    swap = a;
    a = b;
    b = swap;
    printf("\nAfter swapping, value of a,b = %f\n,%f\n",a,b);
    return 0;
}
