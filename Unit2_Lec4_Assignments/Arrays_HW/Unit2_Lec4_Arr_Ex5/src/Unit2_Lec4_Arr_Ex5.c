/*
 ============================================================================
 Name        : Unit2_Lec4_Arr_Ex5.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to search an element in array
 ============================================================================
 */

#include<stdio.h>
int main()
{
   int a[100], n, element, pos=0;
   int i;
   printf("Enter n.of elements: ");
   fflush(stdout);
   scanf("%d", &n);
   for(i=0; i<n; i++)scanf("%d", &a[i]);
   printf("Enter element to search: ");
   fflush(stdout);
   scanf("%d",&element);
   for(i=0; i<n; i++)
   {
     if(a[i]==element)
     {
       printf("%d found at position %d", element, i+1);
       return 0;
     }
   }
   printf("%d not found.", element);
   return 0;
}
