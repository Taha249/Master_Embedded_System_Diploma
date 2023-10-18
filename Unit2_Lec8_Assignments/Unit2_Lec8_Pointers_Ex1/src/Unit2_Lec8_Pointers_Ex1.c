/*
 ============================================================================
 Name        : Unit2_Lec8_Pointers_Ex1.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write a program in C to demonstrate how to handle the pointers in the program.
 ============================================================================
 */

#include <stdio.h>

int main() {
    int num = 12;
    int *ptr;
    ptr = &num;
    printf("Value of 'num': %d\n", num);
    printf("Address of 'num': %p\n", &num);
    printf("Value stored in 'ptr': %p\n", ptr);
    printf("Value pointed by 'ptr': %d\n", *ptr);
    *ptr = 15;
    printf("Updated value of 'num': %d\n", num);
    return 0;
}
