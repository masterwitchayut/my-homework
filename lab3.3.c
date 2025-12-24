#include <stdio.h>

struct student {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
};

void GetStudent( struct student child[][ 10 ], int *room ) {
    printf("Enter number of rooms: ");
    scanf("%d", room);

    for (int i = 0; i < *room; i++) {
        printf("--- Room %d ---\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d name: ", j + 1);
            scanf("%s", child[i][j].name);
            printf("Student %d age: ", j + 1);
            scanf("%d", &child[i][j].age);
            printf("Student %d sex (M/F): ", j + 1);
            scanf(" %c", &child[i][j].sex);
            printf("Student %d gpa: ", j + 1);
            scanf("%f", &child[i][j].gpa);
        }
    }
}

int main() {
    struct student children[ 20 ][ 10 ];
    int group;
    
    
    GetStudent( children, &group );
    
    return 0;
}