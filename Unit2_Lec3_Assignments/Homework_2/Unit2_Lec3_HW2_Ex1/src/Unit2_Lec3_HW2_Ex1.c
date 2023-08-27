/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex1.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to check whether a number is even or odd.
 ============================================================================
 */

#include <stdio.h>

int main(){
	int number;

	printf("Enter an Integer : ");
	fflush(stdout);
	scanf("%d", &number);
	if(number % 2 == 0){
		printf("%d is even\n", number);
	}
	else {
		printf("%d is odd\n", number);
	}
	return 0;
}
