/*
 ============================================================================
 Name        : Unit2_Lec4_Arr_Ex4.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to insert an element in an array
 ============================================================================
 */



#include <stdio.h>

int main()
{
    int arr[50], pos, c, n, value;
    printf("Enter number of elements: ");
    fflush(stdout);
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%d", &arr[c]);

    printf("Enter the location: ");
    fflush(stdout);
    scanf("%d", &pos);
    printf("Enter the element to be inserted: ");
    fflush(stdout);
    scanf("%d", &value);
    for (c = n - 1; c >= pos - 1; c--)
        arr[c+1] = arr[c];

    arr[pos-1] = value;
    printf("The new array: ");
    for (c = 0; c <= n; c++)
        printf("%d", arr[c]);

    return 0;
}
