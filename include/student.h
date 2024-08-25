// student.h
#ifndef STUDENT_H // Include guard to prevent multiple inclusions
#define STUDENT_H

struct Student
{
    int id;
    char name[50];
    int age;
    float gpa;
};

void set_student_name(struct Student *s, const char *name);

struct Student *create_student(int id, const char *name, int age, float gpa);

void print_student(struct Student *s);

#endif