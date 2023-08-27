/*
 ============================================================================
 Name        : Unit2_Lec3_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to Print a Integer Entered by a User
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int number;
	printf("Enter an integer number : ");
	fflush(stdout);
	scanf("%d", &number);
	printf("The number you entered is : %d\n", number);
	return 0;

}
