/*
 ============================================================================
 Name        : Unit2_Lec3_Lab_Ex1.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to calculate the circle area or circumference.
 ============================================================================
 */

#include <stdio.h>

int main() {
    float radius, area, circumference;
    printf("Enter radius: ");
    fflush(stdout);
    scanf("%f", &radius);

    if (radius > 0) {
        area = 3.14159 * radius * radius;
        printf("Area of circle: %.2f cm²\n", area);
    } else {
        printf("Invalid radius. Area cannot be calculated.");
    }

    if (radius > 0) {
        circumference = 6.28318 * radius;
        printf("Circumference of circle: %.2f cm\n", circumference);
    } else {
        printf("Invalid radius. Circumference cannot be calculated.");
    }

    return 0;
}
