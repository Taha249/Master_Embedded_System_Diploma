/*
 * student.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Taha
 */

#ifndef STUDENT_H_
#define STUDENT_H_


#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_COURSES 10
#define MAX_COURSE_LENGTH 20

struct Student {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int rollNumber;
    float gpa;
    char courses[MAX_COURSES][MAX_COURSE_LENGTH];
    int courseCount;
};

void addStudentManually();
void addStudentFromFile(const char* fileName);
void findStudentByRollNumber(int rollNumber);
void findStudentByFirstName(const char* firstName);
void findStudentsByCourse(const char* course);
void findStudentsByCourseID(int courseID);
void countStudents();
void deleteStudentByRollNumber(int rollNumber);
void updateStudentByRollNumber(int rollNumber);
void showAllInformation();



#endif /* STUDENT_H_ */
