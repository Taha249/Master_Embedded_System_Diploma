/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex5.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C program to check whether a character is an alphabet or not.
 ============================================================================
 */

#include <stdio.h>

int main(){
	char ch;
	printf("Enter the character :");
	fflush(stdout);
	scanf("%c", &ch);
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
		printf("%c is an alphabet\n", ch);
	}
	else {
		printf("%c is not an alphabet\n", ch);
	}
	return 0;
}
