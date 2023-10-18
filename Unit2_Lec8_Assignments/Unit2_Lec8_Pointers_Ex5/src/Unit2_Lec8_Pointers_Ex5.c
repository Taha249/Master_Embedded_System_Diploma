/*
 ============================================================================
 Name        : Unit2_Lec8_Pointers_Ex5.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write a program in C to show a pointer to an array which contents are pointer to structure.
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

struct Employee {
char name[50];
int id;
};
int main() {
struct Employee* emp[3];
for(int i=0; i<3; i++) {
	struct Employee emp;
	printf("Employee Name: ");
	fflush(stdout);
	scanf("%s", emp.name);
	printf("Employee ID: ");
	fflush(stdout);
	scanf("%d", &emp.id);
}
for(int i=0; i<3; i++) {
printf("\nEmployee Name: %s\n", emp[i]->name);
printf("Employee ID: %d\n", emp[i]->id);
}
return 0;
}
