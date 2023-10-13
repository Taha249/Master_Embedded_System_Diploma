/*
 ============================================================================
 Name        : Unit2_Lec6_Struct_Union_Enum_Ex5.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to find area of a circle, passing arguments to macros.[Area of circle=pir^2]
 ============================================================================
 */

#include <stdio.h>

#define PI 3.14159
#define AREA_OF_CIRCLE(radius) (PI * (radius) * (radius))

int main() {
    float radius;
    printf("Enter the radius of the circle: ");
    fflush(stdout);
    scanf("%f", &radius);
    float area = AREA_OF_CIRCLE(radius);
    printf("The area of the circle is: %.2f\n", area);
    return 0;
}
