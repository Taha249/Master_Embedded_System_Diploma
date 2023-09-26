/*
 ============================================================================
 Name        : Unit2_Lec4_Arr_Ex1.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to find sum of two matrix of order 2*2 using multidimensional arrays where elements of matrix are entered by user.
 ============================================================================
 */

#include <stdio.h>

int main() {
    float matrix1[2][2], matrix2[2][2], sum[2][2];
    int i, j;

    printf("Enter the elements of the first matrix:\n");
    printf("Enter a11: ");
    fflush(stdout);
    scanf("%f", &matrix1[0][0]);
    printf("Enter a12: ");
    fflush(stdout);
    scanf("%f", &matrix1[0][1]);
    printf("Enter a21: ");
    fflush(stdout);
    scanf("%f", &matrix1[1][0]);
    printf("Enter a22: ");
    fflush(stdout);
    scanf("%f", &matrix1[1][1]);

    printf("\nEnter the elements of the second matrix:\n");
    printf("Enter b11: ");
    fflush(stdout);
    scanf("%f", &matrix2[0][0]);
    printf("Enter b12: ");
    fflush(stdout);
    scanf("%f", &matrix2[0][1]);
    printf("Enter b21: ");
    fflush(stdout);
    scanf("%f", &matrix2[1][0]);
    printf("Enter b22: ");
    fflush(stdout);
    scanf("%f", &matrix2[1][1]);

    printf("\nSum of the matrices:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%.2f ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
