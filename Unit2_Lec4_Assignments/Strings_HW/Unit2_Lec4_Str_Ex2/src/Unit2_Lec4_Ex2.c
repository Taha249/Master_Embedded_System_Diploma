/*
 ============================================================================
 Name        : Unit2_Lec4_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to find the length of a string.
 ============================================================================
 */

#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fflush(stdout);
    scanf("%d", length);
    fgets(str, sizeof(str), stdin);
    while (str[length] != '\0') {
        length++;
    }

    length--;

    printf("Length of the string: %d\n", length);

    return 0;
}
