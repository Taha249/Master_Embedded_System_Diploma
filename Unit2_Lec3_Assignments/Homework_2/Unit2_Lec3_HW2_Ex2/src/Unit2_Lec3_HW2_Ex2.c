/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to check Vowel or Consonant.
 ============================================================================
 */

#include <stdio.h>

int main(){
	char ch;
	printf("Enter a character : ");
	fflush(stdout);
	scanf("%c", &ch);
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		printf("%c is a vowel\n", ch);
	} else {
		printf("%c is a consonant\n", ch);
	}
	return 0;
}
