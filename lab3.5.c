#include <stdio.h>

struct student {
    char name[20];
    int age;
    float gpa;
};

struct student (*GetStudent(int *room))[10];

int main() {
    struct student (*children)[10];
    int group;

    children = GetStudent(&group);

    return 0;
}

struct student (*GetStudent(int *room))[10] {
    int i, j;
    static struct student child[20][10];  // ใช้ static แทน malloc

    printf("Enter number of rooms: ");
    scanf("%d", room);

    for (i = 0; i < *room; i++) {
        printf("Room %d\n", i + 1);
        for (j = 0; j < 10; j++) {
            printf("Student %d\n", j + 1);

            printf("Name: ");
            scanf("%s", child[i][j].name);

            printf("Age: ");
            scanf("%d", &child[i][j].age);

            printf("GPA: ");
            scanf("%f", &child[i][j].gpa);
        }
    }

    return child;
}
