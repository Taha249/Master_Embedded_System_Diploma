/*
 * main.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Taha
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define DPRINTF(...)   {fflush(stdout); \
                        fflush(stdin); \
                        printf(__VA_ARGS__);\
                        fflush(stdout); \
                        fflush(stdin);}

int main() {
    int choice;
    do {
        DPRINTF("\n--- Student Information Management System ---\n");
        DPRINTF("1. Add Student Details manually\n");
        DPRINTF("2. Add Student Details from a text file\n");
        DPRINTF("3. Find Student by Roll Number\n");
        DPRINTF("4. Find Student by First Name\n");
        DPRINTF("5. Find Students registered in a Course\n");
        DPRINTF("6. Find Students Details by Course ID\n");
        DPRINTF("7. Count of Students\n");
        DPRINTF("8. Delete Student Details by Roll Number\n");
        DPRINTF("9. Update Student Details by Roll Number\n");
        DPRINTF("10. Show All Information\n");
        DPRINTF("11. Exit\n");
        DPRINTF("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudentManually();
            break;
        case 2: {
            char fileName[50];
            DPRINTF("Enter the file name: ");
            scanf("%s", fileName);
            addStudentFromFile(fileName);
            break;
        }
        case 3: {
            int rollNumber;
            DPRINTF("Enter the Roll Number: ");
            scanf("%d", &rollNumber);
            findStudentByRollNumber(rollNumber);
            break;
        }
        case 4: {
            char firstName[MAX_NAME_LENGTH];
            DPRINTF("Enter the First Name: ");
            scanf("%s", firstName);
            findStudentByFirstName(firstName);
            break;
        }
        case 5: {
            char course[MAX_COURSE_LENGTH];
            DPRINTF("Enter the Course: ");
            scanf("%s", course);
            findStudentsByCourse(course);
            break;
        }
        case 6: {
            int courseID;
            DPRINTF("Enter the Course ID: ");
            scanf("%d", &courseID);
            findStudentsByCourseID(courseID);
            break;
        }
        case 7:
            countStudents();
            break;
        case 8: {
            int rollNumber;
            DPRINTF("Enter the Roll Number: ");
            scanf("%d", &rollNumber);
            deleteStudentByRollNumber(rollNumber);
            break;
        }
        case 9: {
            int rollNumber;
            DPRINTF("Enter the Roll Number: ");
            scanf("%d", &rollNumber);
            updateStudentByRollNumber(rollNumber);
            break;
        }
        case 10:
            showAllInformation();
            break;
        case 11:
            DPRINTF("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            DPRINTF("Invalid choice. Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}
