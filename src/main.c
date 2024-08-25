#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "student.h"
#include "list.h"

void read_string(char *text, size_t size)
{
    fgets(text, size, stdin);
    fflush(stdin);
    // Remove the newline character if it was read
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n')
    {
        text[len - 1] = '\0';
    }
}

void process_action(struct StudentList *list, int action)
{
    switch (action)
    {
    case 1:
        printf("Enter the student's name:\n");
        char name[50];
        int age;
        float gpa;
        read_string(name, 50);
        scanf("%d", &age);
        scanf("%f", &gpa);
        struct Student *new_student = create_student(get_new_student_id(list), name, age, gpa);
        add_student(list, new_student);
        printf("Student added successfully\n");
        break;
    case 2:
        printf("Enter the student's Id:\n");
        int id_to_find;
        scanf("%d", &id_to_find);
        struct Student *found_student = find_student(list, id_to_find);
        if (found_student == NULL)
        {
            printf("Student not found\n");
        }
        else
        {
            print_student(found_student);
        }
        break;
    case 3:
        printf("Enter the student's Id:\n");
        int id_to_delete;
        scanf("%d", &id_to_delete);
        remove_student_by_id(list, id_to_delete);
        printf("Student deleted successfully!\n");
        break;
    case 4:
        print_students(list);
        break;
    default:
        printf("Invalid action. Try again!\n");
    }
}

int main()
{
    struct StudentList *list = create_list();

    bool continue_loop = true;

    while (continue_loop)
    {
        printf("==================================\n");
        printf("Select action:\n\n1. Add student\n2. Find student by Id\n3. Delete student by Id\n4. Print all students\n5. Exit\n\n");
        int action;
        scanf("%d", &action);
        fflush(stdin);
        if (action == 5)
        {
            continue_loop = false;
        }
        else
        {
            process_action(list, action);
        }
    }

    return 0;
}