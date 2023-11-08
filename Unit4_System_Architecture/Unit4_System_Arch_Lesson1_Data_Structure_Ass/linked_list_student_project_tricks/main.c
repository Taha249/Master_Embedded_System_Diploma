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


// Function to count the number of nodes in the linked list
int CountNodes(struct SStudent* head) {
    int count = 0;
    struct SStudent* current = head;

    while (current != NULL) {
        count++;
        current = current->PNextStudent;
    }

    return count;
}

// Function to get the data value at the Nth index
struct Sdata* GetNth(int index) {
    int count = 0;
    struct SStudent* current = gpFirstStudent;

    while (current != NULL) {
        if (count == index) {
            return &(current->student);
        }
        count++;
        current = current->PNextStudent;
    }

    // Index out of bounds or linked list is empty
    return NULL;
}

// Function to find the value at the n'th node from the end
struct Sdata* NthNodeFromEnd(int n) {
    int length = 0;
    struct SStudent* current = gpFirstStudent;
    while (current != NULL) {
        length++;
        current = current->PNextStudent;
    }

    if (n <= 0 || n > length) {
        return NULL;
    }
    int targetIndex = length - n;
    current = gpFirstStudent;
    for (int i = 0; i < targetIndex; i++) {
        current = current->PNextStudent;
    }
    return &(current->student);
}

// Function to find the middle of the linked list
struct Sdata* FindMiddle() {
    if (gpFirstStudent == NULL) {
        return NULL;
    }
    struct SStudent* slow = gpFirstStudent;
    struct SStudent* fast = gpFirstStudent;

    while (fast != NULL && fast->PNextStudent != NULL) {
        slow = slow->PNextStudent;
        fast = fast->PNextStudent->PNextStudent;
    }
    return &(slow->student);
}

// Function to check if a linked list has a loop
int HasLoop() {
    struct SStudent* tortoise = gpFirstStudent;
    struct SStudent* hare = gpFirstStudent;

    while (tortoise != NULL && hare != NULL && hare->PNextStudent != NULL) {
        tortoise = tortoise->PNextStudent; // Move tortoise one step
        hare = hare->PNextStudent->PNextStudent; // Move hare two steps
        if (tortoise == hare) {
            return 1;
        }
    }
    return 0;
}

// Function to reverse the linked list
void ReverseList() {
    struct SStudent* prev = NULL;
    struct SStudent* current = gpFirstStudent;
    struct SStudent* next;

    while (current != NULL) {
        next = current->PNextStudent;
        current->PNextStudent = prev;
        prev = current;
        current = next;
    }

    gpFirstStudent = prev;
}

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

int main()
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
		DPRINTF("\n 5: CountNodes ") ;
		DPRINTF("\n 6: GetNth");
		DPRINTF("\n 7: NthNodeFromEnd");
		DPRINTF("\n 8: FindMiddle");
		DPRINTF("\n 9: HasLoop");
		DPRINTF("\n 10: ReverseList");
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
		case 5: {
            int nodeCount = CountNodes(gpFirstStudent);
            DPRINTF("\n Number of nodes in the linked list: %d\n", nodeCount);
            break;
        }
		case 6: {
		                DPRINTF("\n Enter the index to get data from: ");
		                gets(temp_text);
		                int index = atoi(temp_text);
		                struct Sdata* data = GetNth(index);
		                if (data != NULL) {
		                    DPRINTF("\n Data at index %d:\n", index);
		                    DPRINTF("\n \t ID: %d", data->ID);
		                    DPRINTF("\n \t Name: %s", data->Name);
		                    DPRINTF("\n \t Height: %f", data->Height);
		                } else {
		                    DPRINTF("\n Index out of bounds or linked list is empty.");
		                }
		                break;
		            }
		case 7: {
		                DPRINTF("\n Enter the value of n: ");
		                gets(temp_text);
		                int n = atoi(temp_text);
		                struct Sdata* data = NthNodeFromEnd(n);
		                if (data != NULL) {
		                    DPRINTF("\n Data at the n-th node from the end:\n");
		                    DPRINTF("\n \t ID: %d", data->ID);
		                    DPRINTF("\n \t Name: %s", data->Name);
		                    DPRINTF("\n \t Height: %f", data->Height);
		                } else {
		                    DPRINTF("\n Invalid value of n or linked list is empty.");
		                }
		                break;
		            }
		case 8: {
		                struct Sdata* middleData = FindMiddle();
		                if (middleData != NULL) {
		                    DPRINTF("\n Data at the middle of the linked list:\n");
		                    DPRINTF("\n \t ID: %d", middleData->ID);
		                    DPRINTF("\n \t Name: %s", middleData->Name);
		                    DPRINTF("\n \t Height: %f", middleData->Height);
		                } else {
		                    DPRINTF("\n Linked list is empty.");
		                }
		                break;
		            }
		 case 9: {
		                int hasLoop = HasLoop();
		                if (hasLoop) {
		                    DPRINTF("\n The linked list has a loop.");
		                } else {
		                    DPRINTF("\n The linked list does not have a loop.");
		                }
		                break;
		            }
		 case 10: {
		                 ReverseList();
		                 DPRINTF("\n Linked list has been reversed.");
		                 break;
		             }
		default:
			DPRINTF("\n Wrong Option ") ;
			break ;
		}
	}
}












