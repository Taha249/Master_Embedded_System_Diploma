/*
 ============================================================================
 Name        : Unit2_Lec8_Pointers_Ex4.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write a program in C to print the elements of an array in reverse.
 ============================================================================
 */

#include <stdio.h>

void printArrayReverse(int arr[], int size) {
    printf("The elements of array in reverse order are:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("element - %d : %d\n", size - i, arr[i]);
    }
}
int main() {
    int size;
    printf("Input the number of elements to store in the array (max 15): ");
    fflush(stdout);
    scanf("%d", &size);
    if (size <= 0 || size > 15) {
        printf("Invalid size. Size should be between 1 and 15.\n");
        return 1;
    }
    int arr[size];
    printf("Input %d number of elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d : ", i + 1);
        fflush(stdout);
        scanf("%d", &arr[i]);
    }
    printArrayReverse(arr, size);
    return 0;
}
