#include <stdio.h>
#include "student.h"

int main()
{
    struct Student student;

    student.id = 1;

    printf("Student id: %d", student.id);

    return 0;
    
}