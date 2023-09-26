/*
 ============================================================================
 Name        : Unit2_Lec4_Str_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to reverse string without using library function.
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
    int start = 0;
    int end = length - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    printf("Reversed string:%s", str);
    return 0;
}
