#include <stdio.h>

void* malloc(unsigned long long size); 
void free(void* ptr);

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct LinkedList {
    struct studentNode *start;
    struct studentNode **now;
};

void copyStr(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void InitList(struct LinkedList *list) {
    list->start = NULL;
    list->now = &(list->start);
}

void InsNode(struct LinkedList *list, char n[], int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    copyStr(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = *(list->now);
    *(list->now) = newNode;
}

void GoNext(struct LinkedList *list) {
    if (*(list->now) != NULL) {
        list->now = &((*(list->now))->next);
    }
}

void DelNode(struct LinkedList *list) {
    if (*(list->now) != NULL) {
        struct studentNode *temp = *(list->now);
        *(list->now) = (*(list->now))->next;
    }
}

void ShowNode(struct LinkedList *list, int mode) {
    if (mode == 0) {
        if (*(list->now) != NULL) {
            struct studentNode *curr = *(list->now);
            printf("%s %d %c %.2f\n", curr->name, curr->age, curr->sex, curr->gpa);
        }
    } else {
        struct studentNode *temp = list->start;
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct LinkedList listA, listB;
    struct LinkedList *listC;

    InitList(&listA);
    InitList(&listB);

    InsNode(&listA, "one", 1, 'A', 1.1);
    InsNode(&listA, "two", 2, 'B', 2.2);
    InsNode(&listA, "three", 3, 'C', 3.3);
    GoNext(&listA);
    ShowNode(&listA, 0);

    InsNode(&listB, "four", 4, 'D', 4.4);
    InsNode(&listB, "five", 5, 'E', 5.5);
    InsNode(&listB, "six", 6, 'F', 6.6);
    GoNext(&listB);
    DelNode(&listB);
    ShowNode(&listB, 1);

    listC = &listA;
    listC->now = &(listC->start);
    ShowNode(listC, 0);

    listC = &listB;
    ShowNode(listC, 1);

    return 0;
}