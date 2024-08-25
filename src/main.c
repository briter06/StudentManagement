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
        struct Student *student = create_student(get_new_student_id(list), name, age, gpa);
        add_student(list, student);
        printf("Student added successfully\n");
        break;
    case 9:
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
        printf("Select action:\n\n1. Add student\n9. Print all students\n10. Exit\n\n");
        int action;
        scanf("%d", &action);
        fflush(stdin);
        if (action == 10)
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