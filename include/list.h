#include "student.h"

struct List
{
    struct Student *pointer;
    int size;
};

struct List create_list();
void add_student(struct List *list, struct Student *s);