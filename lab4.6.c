#include <stdio.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

// จองหน่วยความจำแบบ Static แทนการใช้ malloc/new
struct studentNode pool[ 10 ] ;
int p_idx = 0 ;

void saveNode( struct studentNode *child, char n[], int a, char s, float g ) ;
void GoNext2( struct studentNode ***walk ) ;

int main() {
    struct studentNode *start, *now1, **now2 ;
    
    // สร้าง Linked List 4 โหนด
    start = &pool[ p_idx++ ] ;
    saveNode( start, "one", 6, 'M', 3.11 ) ;

    start->next = &pool[ p_idx++ ] ;
    saveNode( start->next, "two", 8, 'F', 3.22 ) ;

    start->next->next = &pool[ p_idx++ ] ;
    saveNode( start->next->next, "three", 10, 'M', 3.33 ) ;

    start->next->next->next = &pool[ p_idx++ ] ;
    saveNode( start->next->next->next, "four", 12, 'F', 3.44 ) ;
    start->next->next->next->next = NULL ;

    now1 = start ;
    now2 = &now1 ; // ให้ now2 ชี้ไปที่ address ของ now1

    // ส่ง address ของ now2 (&now2) เข้าไปในฟังก์ชัน
    GoNext2( &now2 ) ;
    printf( "%s ", ( *now2 )->name ) ;

    return 0 ;
}

void saveNode( struct studentNode *child, char n[], int a, char s, float g ) {
    int i = 0 ;
    while ( n[ i ] != '\0' && i < 19 ) {
        child->name[ i ] = n[ i ] ;
        i++ ;
    }
    child->name[ i ] = '\0' ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
}

void GoNext2( struct studentNode ***walk ) {
    // ตรวจสอบความถูกต้องของพอยน์เตอร์แต่ละระดับ
    if ( *walk != NULL && **walk != NULL && ( **walk )->next != NULL ) {
        // เปลี่ยนค่าใน now1 (ผ่าน **walk) ให้ชี้ไปโหนดถัดไป
        **walk = ( **walk )->next ;
        printf( "%s ", ( **walk )->name ) ;
    }
}