/*
 * main.c
 *
 *  Created on: Nov 8, 2023
 *      Author: Taha
 */


#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define DPRINTF(...)    {fflush(stdout); \
	                    fflush(stdin); \
	                    printf(__VA_ARGS__); \
	                    fflush(stdout); \
	                    fflush(stdin);}


//Define the effective data
struct Sdata {
	int ID ;
	char Name [40] ;
	float Height ;
};

//Define linked list node
struct SStudent{
	struct Sdata student ;
	struct SStudent* PNextStudent ;
};

struct SStudent* gpFirstStudent = NULL ;

void AddStudent()
{
	struct SStudent* pNewStudent ;
	struct SStudent* pLastStudent ;
	char temp_text [40] ;
	//Check the list , if it is empty == YES
	if(gpFirstStudent == NULL)
	{
		//Create new record
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent)) ;
		//Assign it to gpFirstStudent
		gpFirstStudent = pNewStudent ;
	}
	//Check the list , if it is not empty == NO (list have records)
	else
	{
		//Navigate until reach to the last record
		pLastStudent = gpFirstStudent ;
		while(pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent ;
		//Create new record
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent)) ;
		pLastStudent->PNextStudent = pNewStudent ;

	}

	//Fill the new record
	DPRINTF("\n Enter the ID: ") ;
	gets(temp_text) ;
	pNewStudent->student.ID = atoi(temp_text) ;

	DPRINTF("\n Enter Student Full Name: ") ;
	gets(pNewStudent->student.Name) ;

	DPRINTF("\n Enter the Height: ") ;
	gets(temp_text) ;
	pNewStudent->student.Height = atof(temp_text) ;

	//Set the next pointer (New_Student) to NULL
	pNewStudent->PNextStudent = NULL ;
}

int DeleteStudent()
{
	char temp_text [40] ;
	unsigned int Selected_ID ;

	//Gets the selected ID
	DPRINTF("\n Enter the student ID to be deleted: ") ;
	gets(temp_text) ;
	Selected_ID = atoi(temp_text) ;

	//Is the list not empty
	if(gpFirstStudent)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent ;
		struct SStudent* pPreviousStudent = NULL ;

		//Loop on all the records
		while(pSelectedStudent)
		{
			//Compare each Node with the selected ID
			if(pSelectedStudent->student.ID == Selected_ID)
			{
				if(pPreviousStudent) //The first is not the selected one
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent ;
				}
				else //First student == ID
				{
					gpFirstStudent = pSelectedStudent->PNextStudent ;
				}
				free(pSelectedStudent) ;
				return 1 ;
			}
			pPreviousStudent = pSelectedStudent ;
			pSelectedStudent = pSelectedStudent->PNextStudent ;
		}
	}
	DPRINTF("\n =====Student ID Not Found====") ;
	return 0 ;
}

void ViewStudent()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	int count = 0 ;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n The List is Empty.") ;
	}
	else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n Record Number %d", count+1) ;
			DPRINTF("\n \t ID: %d", pCurrentStudent->student.ID) ;
			DPRINTF("\n \t Name: %s", pCurrentStudent->student.Name) ;
			DPRINTF("\n \t Height: %f", pCurrentStudent->student.Height) ;
			pCurrentStudent = pCurrentStudent->PNextStudent ;
			count++ ;
		}
	}
}

void DeleteAll()
{

	struct SStudent* pCurrentStudent = gpFirstStudent ;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n The List is Empty.") ;
	}
	else
	{
		while(pCurrentStudent)
		{
			struct SStudent* pTempStudent = pCurrentStudent ;
			pCurrentStudent = pCurrentStudent->PNextStudent ;
			free(pTempStudent) ;
		}
		gpFirstStudent = NULL ;
	}
}

void main()
{
	char temp_text [40] ;

	while(1)
	{
		DPRINTF("\n ===========================") ;
		DPRINTF("\n\t Choose one of the following options: \n") ;
		DPRINTF("\n 1: AddStudent ") ;
		DPRINTF("\n 2: DeleteStudent ") ;
		DPRINTF("\n 3: ViewStudent ") ;
		DPRINTF("\n 4: DeleteAll ") ;
		DPRINTF("\n Enter option number: ") ;

		gets(temp_text) ;
		DPRINTF("\n ============================") ;
		switch(atoi (temp_text))
		{
		case 1:
			AddStudent() ;
			break ;
		case 2:
			DeleteStudent() ;
			break ;
		case 3:
			ViewStudent() ;
			break ;
		case 4:
			DeleteAll() ;
			break ;
		default:
			DPRINTF("\n Wrong Option ") ;
			break ;
		}
	}
}







