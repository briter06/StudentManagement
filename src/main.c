#include <stdio.h>
#include "student.h"
#include "list.h"

int main()
{
    struct List list = create_list();

    struct Student student1 = create_student(1, "Briter Gonzalez", 24, 18.2);
    add_student(&list, &student1);

    struct Student student2 = create_student(2, "Andres Daza", 14, 11.96);
    add_student(&list, &student2);

    for (int i = 0; i < list.size; i++)
    {
        print_student(list.pointer[i]);
        printf("\n");
    }

    return 0;
}