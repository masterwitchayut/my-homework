#include <stdio.h>

// สร้าง Macro เพื่อให้ภาษา C รู้จักคำว่า new และทำงานเหมือน C++
#define new (struct studentNode*)malloc(sizeof(struct studentNode))

// เนื่องจากไม่ใช้ stdlib.h จึงต้องประกาศ prototype ของ malloc เองเพื่อไม่ให้ error
void* malloc(size_t size);

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
    struct studentNode *start, *now1, **now2;
    
    // บรรทัดเหล่านี้จะเขียนตาม Pre-code เป๊ะๆ และไม่ Error แล้ว
    start = new struct studentNode;
    saveNode( start, "one", 6, 'M', 3.11 );

    start->next = new struct studentNode;
    saveNode( start->next, "two", 8, 'F', 3.22 );

    start->next->next = new struct studentNode;
    saveNode( start->next->next, "three", 10, 'M', 3.33 );

    start->next->next->next = new struct studentNode;
    saveNode( start->next->next->next, "four", 12, 'F', 3.44 );

    now1 = start;
    now2 = &start;

    GoNext2( now2 );
    printf( "%s ", (*now2)->name );

    return 0;
}

void saveNode( struct studentNode *child, char n[], int a, char s, float g ) {
    // การ copy string แบบ manual เพื่อเลี่ยง string.h
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