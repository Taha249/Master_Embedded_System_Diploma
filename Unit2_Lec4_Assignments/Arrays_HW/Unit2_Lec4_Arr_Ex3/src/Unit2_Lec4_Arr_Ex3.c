/*
 ============================================================================
 Name        : Unit2_Lec4_Arr_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to asks user to enter a matrix(size of matrix is specified by user) and this program finds the transpose of that matrix and displays it.
 ============================================================================
 */
#include <stdio.h>
int main() {
  int a[4][4], transpose[4][4], r, c;
  printf("Enter n.of rows: ");
  fflush(stdout);
  scanf("%d", &r);
  printf("Enter n.of columns: ");
  fflush(stdout);
  scanf("%d", &c);
  printf("\nEnter matrix elements:\n");
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) {
    printf("Enter element a%d%d: ", i + 1, j + 1);
    fflush(stdout);
    scanf("%d", &a[i][j]);
  }
  printf("\nEntered matrix: \n");
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) {
    printf("%d  ", a[i][j]);
    if (j == c - 1)
    printf("\n");
  }
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) {
    transpose[j][i] = a[i][j];
  }
  printf("\nTranspose of the matrix:\n");
  for (int i = 0; i < c; ++i)
  for (int j = 0; j < r; ++j) {
    printf("%d  ", transpose[i][j]);
    if (j == r - 1)
    printf("\n");
  }
  return 0;
}
