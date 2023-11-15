/*
 * main.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Taha
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_COURSES 10
#define MAX_COURSE_LENGTH 20

#define DPRINTF(...)   {fflush(stdout); \
	                    fflush(stdin); \
	                    printf(__VA_ARGS__);\
	                    fflush(stdout); \
	                    fflush(stdin);}

struct Student {
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	int rollNumber;
	float gpa;
	char courses[MAX_COURSES][MAX_COURSE_LENGTH];
	int courseCount;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudentManually() {
	if (studentCount >= MAX_STUDENTS) {
		DPRINTF("Maximum number of students reached.\n");
		return;
	}

	struct Student newStudent;
	DPRINTF("Enter the first name: ");
	scanf("%s", newStudent.firstName);
	DPRINTF("Enter the last name: ");
	scanf("%s", newStudent.lastName);
	DPRINTF("Enter the roll number: ");
	scanf("%d", &newStudent.rollNumber);
	DPRINTF("Enter the GPA: ");
	scanf("%f", &newStudent.gpa);

	int numCourses;
	DPRINTF("Enter the number of courses registered: ");
	scanf("%d", &numCourses);
	DPRINTF("Enter the courses (separated by spaces): ");
	for (int i = 0; i < numCourses; i++) {
		scanf("%s", newStudent.courses[i]);
	}
	newStudent.courseCount = numCourses;

	students[studentCount++] = newStudent;
	DPRINTF("Student details added successfully.\n");
}

void addStudentFromFile(const char* fileName) {
	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		DPRINTF("Failed to open the file.\n");
		return;
	}

	while (!feof(file) && studentCount < MAX_STUDENTS) {
		struct Student newStudent;
		fscanf(file, "%s %s %d %f", newStudent.firstName, newStudent.lastName, &newStudent.rollNumber, &newStudent.gpa);

		int numCourses;
		fscanf(file, "%d", &numCourses);
		for (int i = 0; i < numCourses; i++) {
			fscanf(file, "%s", newStudent.courses[i]);
		}
		newStudent.courseCount = numCourses;

		students[studentCount++] = newStudent;
	}

	fclose(file);
	DPRINTF("Student details added from file successfully.\n");
}

void findStudentByRollNumber(int rollNumber) {
	for (int i = 0; i < studentCount; i++) {
		if (students[i].rollNumber == rollNumber) {
			DPRINTF("Student Found:\n");
			DPRINTF("First Name: %s\n", students[i].firstName);
			DPRINTF("Last Name: %s\n", students[i].lastName);
			DPRINTF("Roll Number: %d\n", students[i].rollNumber);
			DPRINTF("GPA: %.2f\n", students[i].gpa);
			DPRINTF("Courses Registered: ");
			for (int j = 0; j < students[i].courseCount; j++) {
				DPRINTF("%s ", students[i].courses[j]);
			}
			DPRINTF("\n");
			return;
		}
	}
	DPRINTF("Student with roll number %d not found.\n", rollNumber);
}

void findStudentByFirstName(const char* firstName) {
	for (int i = 0; i < studentCount; i++) {
		if (strcmp(students[i].firstName, firstName) == 0) {
			DPRINTF("Student Found:\n");
			DPRINTF("First Name: %s\n", students[i].firstName);
			DPRINTF("Last Name: %s\n", students[i].lastName);
			DPRINTF("Roll Number: %d\n", students[i].rollNumber);
			DPRINTF("GPA: %.2f\n", students[i].gpa);
			DPRINTF("Courses Registered: ");
			for (int j = 0; j < students[i].courseCount; j++) {
				DPRINTF("%s ", students[i].courses[j]);
			}
			DPRINTF("\n");
			return;
		}
	}
	DPRINTF("Student with first name %s not found.\n", firstName);
}

void findStudentsByCourse(const char* course) {
	DPRINTF("Students registered in course %s:\n", course);
	for (int i = 0; i < studentCount; i++) {
		for (int j = 0; j < students[i].courseCount; j++) {
			if (strcmp(students[i].courses[j], course) == 0) {
				DPRINTF("First Name: %s\n", students[i].firstName);
				DPRINTF("Last Name: %s\n", students[i].lastName);
				DPRINTF("Roll Number: %d\n", students[i].rollNumber);
				DPRINTF("GPA: %.2f\n", students[i].gpa);
				DPRINTF("\n");
				break;
			}
		}
	}
}

void findStudentsByCourseID(int courseID) {
	DPRINTF("Students registered in course with ID %d:\n", courseID);
	for (int i = 0; i < studentCount; i++) {
		for (int j = 0; j < students[i].courseCount; j++) {
			int courseIDFromName = students[i].courses[j][strlen(students[i].courses[j]) - 1] - '0';
			if (courseIDFromName == courseID) {
				DPRINTF("First Name: %s\n", students[i].firstName);
				DPRINTF("Last Name: %s\n", students[i].lastName);
				DPRINTF("Roll Number: %d\n", students[i].rollNumber);
				DPRINTF("GPA: %.2f\n", students[i].gpa);
				DPRINTF("\n");
				break;
			}
		}
	}
}

void countStudents() {
	DPRINTF("Total number of students: %d\n", studentCount);
}

void deleteStudentByRollNumber(int rollNumber) {
	for (int i = 0; i < studentCount; i++) {
		if (students[i].rollNumber == rollNumber) {
			for (int j = i; j < studentCount - 1; j++) {
				students[j] = students[j + 1];
			}
			studentCount--;
			DPRINTF("Student with roll number %d deleted successfully.\n", rollNumber);
			return;
		}
	}
	DPRINTF("Student with roll number %d not found.\n", rollNumber);
}

void updateStudentByRollNumber(int rollNumber) {
	for (int i = 0; i < studentCount; i++) {
		if (students[i].rollNumber == rollNumber) {
			DPRINTF("Enter the new first name: ");
			scanf("%s", students[i].firstName);
			DPRINTF("Enter the new last name: ");
			scanf("%s", students[i].lastName);
			DPRINTF("Enter the new GPA: ");
			scanf("%f", &students[i].gpa);

			int numCourses;
			DPRINTF("Enter the number of new courses registered: ");
			scanf("%d", &numCourses);
			DPRINTF("Enter the new courses (separated by spaces): ");
			for (int j = 0; j < numCourses; j++) {
				scanf("%s", students[i].courses[j]);
			}
			students[i].courseCount = numCourses;

			DPRINTF("Student details updated successfully.\n");
			return;
		}
	}
	DPRINTF("Student with roll number %d not found.\n", rollNumber);
}

void showAllInformation() {
	DPRINTF("All Student Information:\n");
	for (int i = 0; i < studentCount; i++) {
		DPRINTF("First Name: %s\n", students[i].firstName);
		DPRINTF("Last Name: %s\n", students[i].lastName);
		DPRINTF("Roll Number: %d\n", students[i].rollNumber);
		DPRINTF("GPA: %.2f\n", students[i].gpa);
		DPRINTF("Courses Registered: ");
		for (int j = 0; j < students[i].courseCount; j++) {
			DPRINTF("%s ", students[i].courses[j]);
		}
		DPRINTF("\n");
	}
}

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
