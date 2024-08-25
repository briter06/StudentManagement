#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void set_student_name(struct Student *s, const char *name)
{
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
}

struct Student *create_student(int id, const char *name, int age, float gpa)
{
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    if (student == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }
    student->id = id;
    set_student_name(student, name);
    student->age = age;
    student->gpa = gpa;
    return student;
}

void print_student(struct Student *s)
{
    printf("Student %d\n\tName: %s\n\tAge: %d\n\tGPA: %.2f\n", s->id, s->name, s->age, s->gpa);
}