/*
 ============================================================================
 Name        : Unit2_Lec6_Struct_Union_Enum_Ex4.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to store information of students using structure.
 ============================================================================
 */

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};
int main() {
    struct Student students[10];
    int i;
    for (i = 0; i < 4; i++) {
        printf("Enter information of students:\n");
        printf("Enter roll number: ");
        fflush(stdout);
        scanf("%d", &students[i].roll);
        printf("Enter name: ");
        fflush(stdout);
        scanf("%s", students[i].name);
        printf("Enter marks: ");
        fflush(stdout);
        scanf("%f", &students[i].marks);
    }
    printf("\nStudent Details:\n");
    for (i = 0; i < 4; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll: %d\n", students[i].roll);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    return 0;
}
