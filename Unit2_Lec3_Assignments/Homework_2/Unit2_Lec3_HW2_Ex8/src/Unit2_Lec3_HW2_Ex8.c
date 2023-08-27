/*
 ============================================================================
 Name        : Unit2_Lec3_HW2_Ex8.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to make a simple calculator to add, subtract, multiply, or divide using switch case.
 ============================================================================
 */

#include <stdio.h>

int main() {
    float num1, num2, result;
    char operation;
    printf("Enter first number: ");
    fflush(stdout);
    scanf("%f", &num1);
    printf("Enter operation (+, -, *, /): ");
    fflush(stdout);
    scanf(" %c", &operation);
    printf("Enter second number: ");
    fflush(stdout);
    scanf("%f", &num2);

    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation");
            return 0;
    }

    printf("Result: %.2f", result);
    return 0;
}
