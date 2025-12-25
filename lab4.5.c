#include <stdio.h>

struct studentNode {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void saveNode( struct studentNode *child, char n[], int a, char s, float g );
void GoNext2( struct studentNode **walk );

int main() {
    // จองพื้นที่แบบ Static (Array) เพื่อเลี่ยงการใช้ new หรือ malloc
    struct studentNode nodes[4]; 
    struct studentNode *start, *now1, **now2;

    start = &nodes[0];
    saveNode( start, "one", 6, 'M', 3.11 );

    start->next = &nodes[1];
    saveNode( start->next, "two", 8, 'F', 3.22 );

    start->next->next = &nodes[2];
    saveNode( start->next->next, "three", 10, 'M', 3.33 );

    start->next->next->next = &nodes[3];
    saveNode( start->next->next->next, "four", 12, 'F', 3.44 );

    now1 = start;
    now2 = &start;

    GoNext2( now2 );
    printf( "%s ", (*now2)->name );

    return 0;
}

void saveNode( struct studentNode *child, char n[], int a, char s, float g ) {
    // การ copy string โดยไม่ใช้ string.h
    int i = 0;
    while (n[i] != '\0' && i < 19) {
        child->name[i] = n[i];
        i++;
    }
    child->name[i] = '\0';
    
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

void GoNext2( struct studentNode **walk ) {
    if (*walk != NULL && (*walk)->next != NULL) {
        *walk = (*walk)->next;
    }
}