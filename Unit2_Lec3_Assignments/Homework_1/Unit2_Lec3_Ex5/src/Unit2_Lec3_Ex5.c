/*
 ============================================================================
 Name        : Unit2_Lec3_Ex5.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to Find ASCII Value of a Character
 ============================================================================
 */

#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    fflush(stdout);
    scanf("%c", &ch);
    printf("The ASCII value of '%c' is: %d\n", ch, ch);
    return 0;
}
