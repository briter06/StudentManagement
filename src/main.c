#include <stdio.h>
#include "student.h"

int main()
{
    struct Student student;

    student.id = 1;
    set_student_name(&student, "Briter Gonzalez");

    printf("Student id: %d\n", student.id);
    printf("Student name: %s\n", student.name);

    return 0;
}