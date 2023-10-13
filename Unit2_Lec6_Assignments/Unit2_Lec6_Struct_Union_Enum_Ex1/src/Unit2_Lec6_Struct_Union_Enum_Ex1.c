/*
 ============================================================================
 Name        : Unit2_Lec6_Struct_Union_Enum_Ex1.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to store information(name,roll and marks)of a student using structure.
 ============================================================================
 */

#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};
int main() {
    struct Student student;

    printf("Enter student's name: ");
    fflush(stdout);
    scanf("%s", student.name);
    printf("Enter student's roll number: ");
    fflush(stdout);
    scanf("%d", &student.rollNumber);
    printf("Enter student's marks: ");
    fflush(stdout);
    scanf("%f", &student.marks);
    printf("\nStudent's Information:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks: %.2f\n", student.marks);

    return 0;
}
