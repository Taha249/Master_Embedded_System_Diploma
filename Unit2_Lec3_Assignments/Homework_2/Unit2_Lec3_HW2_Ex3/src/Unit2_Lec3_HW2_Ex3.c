/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to fins the largest number among three numbers.
 ============================================================================
 */

#include <stdio.h>

int main() {
    float num1, num2, num3, largest;
    printf("Enter three numbers: ");
    fflush(stdout);
    scanf("%f %f %f", &num1, &num2, &num3);
    largest = num1;
    if (num2 > largest) {
        largest = num2;
    }
    if (num3 > largest) {
        largest = num3;
    }
    printf("The largest number is: %f\n", largest);
    return 0;
}
