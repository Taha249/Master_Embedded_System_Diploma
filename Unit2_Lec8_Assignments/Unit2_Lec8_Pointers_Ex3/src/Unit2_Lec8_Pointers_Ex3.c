/*
 ============================================================================
 Name        : Unit2_Lec8_Pointers_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write a program in C to print a string in reverse using a pointer.
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fflush(stdout);
    scanf("%99[^\n]", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
