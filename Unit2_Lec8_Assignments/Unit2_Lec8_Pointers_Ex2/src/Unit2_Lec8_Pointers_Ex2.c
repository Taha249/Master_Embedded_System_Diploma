/*
 ============================================================================
 Name        : Unit2_Lec8_Pointers_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write a program in C to print all alphabets using a pointer.
 ============================================================================
 */

#include <stdio.h>

int main() {
    char *ptr;
    char alphabet = 'A';
    ptr = &alphabet;
    printf("Alphabets: ");
    while (*ptr <= 'Z') {
        printf("%c ", *ptr);
        (*ptr)++;
    }
    printf("\n");
    return 0;
}
