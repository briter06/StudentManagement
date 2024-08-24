#include "student.h"
#include <string.h>

struct Student set_student_name(struct Student *s, const char *name)
{
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    return *s;
}