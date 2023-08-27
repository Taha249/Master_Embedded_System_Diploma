/*
 ============================================================================
 Name        : Unit2_Lec3_Lab_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to calculate the minimum of two numbers.
 ============================================================================
 */

#include <stdio.h>

int main() {
    int n1, n2, mini;
    printf("Enter two numbers: ");
    fflush(stdout);
    scanf("%d %d", &n1, &n2);
    mini = n1 < n2 ? n1 : n2;
    printf("The minimum of %d and %d is %d", n1, n2, mini);
    return 0;
}
