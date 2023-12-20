/*
 * student.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Taha
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct Student students[MAX_STUDENTS];
int studentCount = 0;

#define DPRINTF(...)   {fflush(stdout); \
                        fflush(stdin); \
                        printf(__VA_ARGS__);\
                        fflush(stdout); \
                        fflush(stdin);}


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
