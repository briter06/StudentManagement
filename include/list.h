#include "student.h"

struct StudentList
{
    struct Student **pointer;
    int size;
};

struct StudentList *create_list();
void add_student(struct StudentList *list, struct Student *s);
int index_of_student(struct StudentList *list, int id);
struct Student *find_student(struct StudentList *list, int id);
void remove_student_at(struct StudentList *list, int index);
void print_students(struct StudentList *list);
void remove_student_by_id(struct StudentList *list, int id);