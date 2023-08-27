/*
 ============================================================================
 Name        : Unit2_Lec3_Lab_Ex4.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to calculate the average students degree for any given students number.
 ============================================================================
 */

#include <stdio.h>

int main() {
    int num_students, sum_degrees = 0, i;
    printf("Enter number of students: ");
    fflush(stdout);
    scanf("%d", &num_students);
    for (i = 1; i <= num_students; i++) {
        printf("Enter student %d degree: ", i);
        fflush(stdout);
        scanf("%d", &sum_degrees);
    }
    sum_degrees /= num_students;
    printf("Average degree of students is: %d", sum_degrees);
    return 0;
}
