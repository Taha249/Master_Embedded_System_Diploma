/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex7.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to find the factorial of a number.
 ============================================================================
 */

#include <stdio.h>

int main() {
    int num, factorial = 1;
    printf("Enter a number: ");
    fflush(stdout);
    scanf("%d", &num);
    while (num > 0) {
        factorial *= num;
        num--;
    }
    printf("Factorial of %d is %d", num, factorial);
    return 0;
}
