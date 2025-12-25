#include <stdio.h>

struct student {
    int id;
    char name[50];
};

struct student (*GetStudent(int *room))[10] {
    static struct student data[100][10]; 
    
    printf("Enter number of rooms: ");
    scanf("%d", room);

    for (int i = 0; i < *room; i++) {
        for (int j = 0; j < 10; j++) {
            printf("Room %d - Student %d ID: ", i + 1, j + 1);
            scanf("%d", &data[i][j].id);
            printf("Room %d - Student %d Name: ", i + 1, j + 1);
            scanf("%s", data[i][j].name);
        }
    }
    return data;
}

int main() {
    struct student (*children)[10];
    int group;

    children = GetStudent(&group);

    return 0;
}