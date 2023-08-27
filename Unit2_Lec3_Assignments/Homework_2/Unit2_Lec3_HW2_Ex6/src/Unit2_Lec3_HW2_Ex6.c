/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex6.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to calculate sum of natural numbers.
 ============================================================================
 */

#include <stdio.h>

int main() {
    int n, i, sum = 0;
    printf("Enter a positive integer: ");
    fflush(stdout);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    printf("The sum of natural numbers %d is: %d\n", n, sum);
    return 0;
}
