/*
 ============================================================================
 Name        : Unit2_Lec5_Funct_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to calculate factorial of a number using recursion.
 ============================================================================
 */
#include <stdio.h>

int factorial(int num);

int main() {
    int num;

    printf("Enter a positive integer: ");
    fflush(stdout);
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
    return 0;
}

int factorial(int num) {
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}
