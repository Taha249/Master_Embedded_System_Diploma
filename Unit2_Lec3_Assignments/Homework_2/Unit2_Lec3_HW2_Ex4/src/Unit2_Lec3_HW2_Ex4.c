/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex4.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C program to check whether a number is positive or negative.
 ============================================================================
 */

#include <stdio.h>

int main(){
	int number;
	printf("Enter the number : ");
	fflush(stdout);
	scanf("%d", &number);
	if (number > 0){
		printf("%d is positive\n", number);
	}
	else if (number < 0){
		printf("%d is negative\n", number);
	}
	else {
		printf("The number is Zero\n");
	}
	return 0;
}
