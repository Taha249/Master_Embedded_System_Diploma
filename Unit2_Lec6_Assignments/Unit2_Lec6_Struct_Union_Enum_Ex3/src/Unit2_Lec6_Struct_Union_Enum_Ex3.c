/*
 ============================================================================
 Name        : Unit2_Lec6_Struct_Union_Enum_Ex3.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to add two complex numbers by passing structure to a function.
 ============================================================================
 */

#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}
int main() {
    struct Complex num1, num2, sum;
    printf("Enter real and imaginary parts of first complex number:\n");
    fflush(stdout);
    scanf("%f %f", &num1.real, &num1.imaginary);
    printf("Enter real and imaginary parts of second complex number:\n");
    fflush(stdout);
    scanf("%f %f", &num2.real, &num2.imaginary);
    sum = addComplex(num1, num2);
    printf("Sum = %.2f + %.2fi\n", sum.real, sum.imaginary);
    return 0;
}
