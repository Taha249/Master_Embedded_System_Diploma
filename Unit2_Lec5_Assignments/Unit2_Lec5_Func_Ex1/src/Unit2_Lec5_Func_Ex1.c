/*
 ============================================================================
 Name        : Unit2_Lec5_Func_Ex1.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to Prime numbers between two intervals by making user-defined function.
 ============================================================================
 */

#include <stdio.h>
int isPrime(int num);
int main() {
    int start, end, i;
    printf("Enter the starting number: ");
    fflush(stdout);
    scanf("%d", &start);
    printf("Enter the ending number: ");
    fflush(stdout);
    scanf("%d", &end);
    printf("Prime numbers between %d and %d are: ", start, end);
    for (i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
int isPrime(int num) {
    int i;
    if (num <= 1) {
        return 0;
    }
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
