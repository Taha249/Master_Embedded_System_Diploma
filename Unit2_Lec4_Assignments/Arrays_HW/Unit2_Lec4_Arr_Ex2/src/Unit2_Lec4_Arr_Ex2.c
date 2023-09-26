/*
 ============================================================================
 Name        : Unit2_Lec4_Arr_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to takes n number of elements from user, stores data in and array and calculates the average of those numbers.
 ============================================================================
 */

#include <stdio.h>
int main() {
    int n, i;
    float num[100], sum = 0.0, avg;
    printf("Enter the numbers of elements: ");
    fflush(stdout);
    scanf("%d", &n);
    while (n > 100 || n < 1) {
        printf("Error! number should in range of (1 to 100).\n");
        printf("Enter the number again: ");
        fflush(stdout);
        scanf("%d", &n);
    }
    for (i = 0; i < n; ++i) {
        printf("%d. Enter number: ", i + 1);
        fflush(stdout);
        scanf("%f", &num[i]);
        sum += num[i];
    }
    avg = sum / n;
    printf("Average = %.2f", avg);
    return 0;
}
