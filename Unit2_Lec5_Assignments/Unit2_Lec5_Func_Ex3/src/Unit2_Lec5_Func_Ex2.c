/*
 ============================================================================
 Name        : Unit2_Lec5_Func_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to reverse a sentence using recursion.
 ============================================================================
 */

#include <stdio.h>

void reverseSentence();

int main()
{
    printf("Enter a sentence: ");
    fflush(stdout);
    reverseSentence();
    printf("\n");

    return 0;
}

void reverseSentence()
{
    char c;
    scanf("%c", &c);

    if (c != '\n') {
        reverseSentence();
        printf("%c", c);
    }
}
