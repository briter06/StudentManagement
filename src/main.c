#include <stdio.h>
#include "student.h"

int main()
{
    struct Student student = create_student(1, "Briter Gonzalez", 24, 18.2);

    print_student(student);

    return 0;
}