/*
 ============================================================================
 Name        : Unit2_Lec6_Struct_Union_Enum_Ex6.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write the output of this program.
 ============================================================================
 */

#include <stdio.h>

union job{
	char name[32];
	float salary;
	int worker_no;
}u ;
struct job1{
	char name[32];
	float salary;
	int worker_no;
}s ;
int main(){
	printf("size of union=%d", sizeof(u));
	printf("\nsize of structure=%d", sizeof(s));
	return 0;
}
