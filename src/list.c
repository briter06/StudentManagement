#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"

struct StudentList *create_list()
{
    struct StudentList *list = (struct StudentList *)malloc(sizeof(struct StudentList));
    list->size = 0;
    list->pointer = malloc(0);
    return list;
}

void add_student(struct StudentList *list, struct Student *x)
{
    int new_size = list->size + 1;
    struct Student **new_list = (struct Student **)realloc(list->pointer, sizeof(struct Student) * new_size);
    if (new_list == NULL && new_size > 0)
    {
        /* No memory available */
        exit(EXIT_FAILURE);
    }
    new_list[list->size] = x;
    list->pointer = new_list;
    list->size += 1;
}

struct Student *find_student(struct StudentList *list, int id)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->pointer[i]->id == id)
        {
            return list->pointer[i];
        }
    }
    return NULL;
}

int index_of_student(struct StudentList *list, int id)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->pointer[i]->id == id)
        {
            return i;
        }
    }
    return -1;
}

void remove_student_at(struct StudentList *list, int index)
{
    if (list->size <= 0 || index < 0 || index >= list->size)
    {
        // Invalid index or array
        exit(EXIT_FAILURE);
    }
    int new_size = list->size - 1;
    free(list->pointer[new_size]);
    for (int i = index; i < new_size; i++)
    {
        list->pointer[i] = list->pointer[i + 1];
    }
    struct Student **new_list = (struct Student **)realloc(list->pointer, sizeof(struct Student) * new_size);
    if (new_list == NULL && new_size > 0)
    {
        /* No memory available */
        exit(EXIT_FAILURE);
    }

    list->pointer = new_list;
    list->size = new_size;
}

void remove_student_by_id(struct StudentList *list, int id)
{
    int index = index_of_student(list, id);
    if (index == -1)
    {
        exit(EXIT_FAILURE);
    }
    remove_student_at(list, index);
}

void print_students(struct StudentList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        print_student(list->pointer[i]);
        printf("\n");
    }
}

int get_new_student_id(struct StudentList *list)
{
    if (list->size == 0)
    {
        return 0;
    }
    return list->pointer[list->size - 1]->id + 1;
}