#include <stdio.h>
#include <string.h>
#include "student.h"

struct Student set_student_name(struct Student *s, const char *name)
{
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    return *s;
}

struct Student create_student(int id, const char *name, int age, float gpa)
{
    struct Student student;
    student.id = id;
    set_student_name(&student, name);
    student.age = age;
    student.gpa = gpa;
    return student;
}

void print_student(struct Student s)
{
    printf("Student %d\n\tName: %s\n\tAge: %d\n\tGPA: %.2f\n", s.id, s.name, s.age, s.gpa);
}