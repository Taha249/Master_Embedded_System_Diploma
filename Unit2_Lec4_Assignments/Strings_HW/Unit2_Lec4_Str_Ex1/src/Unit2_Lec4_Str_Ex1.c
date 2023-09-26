/*
 ============================================================================
 Name        : Unit2_Lec4_Str_Ex1.c
 Author      : Taha Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Write C program to find the frequency of characters in a string.
 ============================================================================
 */

#include <stdio.h>
int main(){
   char str[1000],choice;
   int i,ctr=0;

	printf("Enter the string : ");
    fgets(str,sizeof str,stdin);

   printf("Input the character to find frequency: ");
   scanf("%c",&choice);
   for(i=0;str[i]!='\0';++i)
   {
       if(choice==str[i])
           ++ctr;
   }
   printf("The frequency of '%c' is : %d\n\n", choice, ctr);
}
