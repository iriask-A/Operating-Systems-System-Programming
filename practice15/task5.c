#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    int n = 3;

    Student *students = (Student*) malloc(n * sizeof(Student));
    if (!students) return 1;

    students[0] = (Student){1, "Aizat", 3.8f};
    students[1] = (Student){2, "Bekzat", 3.5f};
    students[2] = (Student){3, "Daniya", 3.9f};

    printf("%-5s %-15s %s\n", "ID", "Name", "GPA");
    printf("---------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-5d %-15s %.1f\n",
               students[i].id, students[i].name, students[i].gpa);

    free(students);
    students = NULL;
    return 0;
}
