/*
 ============================================================================
 Name        : Unit2_Lec6_Struct_Union_Enum_Ex2.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to add two distances(in inch-feet)system using structures.
 ============================================================================
 */
#include <stdio.h>

struct distance {
  int feet;
  float inch;
};
int main() {
  struct distance dist1, dist2, sum;
  printf("Enter 1st feet: ");
  fflush(stdout);
  scanf("%d", &dist1.feet);
  printf("Enter 1st inches: ");
  fflush(stdout);
  scanf("%f", &dist1.inch);
  printf("Enter 2nd feet: ");
  fflush(stdout);
  scanf("%d", &dist2.feet);
  printf("Enter 2nd inches: ");
  fflush(stdout);
  scanf("%f", &dist2.inch);

  sum.feet = dist1.feet + dist2.feet;
  sum.inch = dist1.inch + dist2.inch;

  if(sum.inch >= 12.0){
    sum.feet += 1;
    sum.inch -= 12.0;
  }
  printf("Sum of distances = %d feet %f inches", sum.feet, sum.inch);
  return 0;
}
