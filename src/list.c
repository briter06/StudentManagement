#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"

struct List create_list()
{
    struct List list;
    list.size = 0;
    list.pointer = malloc(0);
    return list;
}

void add_student(struct List *list, struct Student *x)
{
    list->pointer = realloc(list->pointer, sizeof(struct Student) * (list->size + 1));
    list->pointer[list->size] = *x;
    list->size += 1;
}