// student.h
#ifndef STUDENT_H   // Include guard to prevent multiple inclusions
#define STUDENT_H

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

// struct Student set_student_name(struct Strudent *s, const char *name);

#endif