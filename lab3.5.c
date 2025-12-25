#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
};

struct student (*GetStudent(int *room))[10] {
    printf("Enter number of rooms: ");
    scanf("%d", room);

    // จองหน่วยความจำสำหรับจำนวนห้องที่ระบุ โดยแต่ละห้องมีนักเรียน 10 คน
    struct student (*data)[10] = malloc(sizeof(struct student[10]) * (*room));

    for (int i = 0; i < *room; i++) {
        printf("--- Room %d ---\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d ID: ", j + 1);
            scanf("%d", &data[i][j].id);
            printf("Student %d Name: ", j + 1);
            scanf("%s", data[i][j].name);
        }
    }
    return data;
}

int main() {
    struct student (*children)[10];
    int group;

    children = GetStudent(&group);

    // ส่วนการคืนหน่วยความจำ (Optional)
    if (children != NULL) {
        free(children);
    }

    return 0;
}