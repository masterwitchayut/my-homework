#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

typedef struct {
    struct studentNode *start, **now ;
} LinkedList ;

void initList( LinkedList *l ) {
    l->start = NULL ;
    l->now = &l->start ;
}

void InsNode( LinkedList *l, char n[], int a, char s, float g ) {
    struct studentNode *newNode = ( struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    strcpy( newNode->name, n ) ;
    newNode->age = a ;
    newNode->sex = s ;
    newNode->gpa = g ;
    newNode->next = *l->now ;
    *l->now = newNode ;
}

void DelNode( LinkedList *l ) {
    if ( *l->now != NULL ) {
        struct studentNode *temp = *l->now ;
        *l->now = ( *l->now )->next ;
        free( temp ) ;
    }
}

void GoNext( LinkedList *l ) {
    if ( *l->now != NULL ) {
        l->now = &( ( *l->now )->next ) ;
    }
}

void GoFirst( LinkedList *l ) {
    l->now = &l->start ;
}

void GoLast( LinkedList *l ) {
    GoFirst( l ) ;
    while ( *l->now != NULL ) {
        l->now = &( ( *l->now )->next ) ;
    }
}

void ShowAll( LinkedList *l ) {
    struct studentNode *temp = l->start ;
    while ( temp != NULL ) {
        printf( "Name: %-15s | Age: %-3d | Sex: %c | GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa ) ;
        temp = temp->next ;
    }
}

int FindNode( LinkedList *l, char n[] ) {
    GoFirst( l ) ;
    while ( *l->now != NULL ) {
        if ( strcmp( ( *l->now )->name, n ) == 0 ) return 1 ;
        GoNext( l ) ;
    }
    return 0 ;
}

struct studentNode *NowNode( LinkedList *l ) {
    return *l->now ;
}

void EditNode( LinkedList *l, char n[], int a, char s, float g ) {
    if ( *l->now != NULL ) {
        strcpy( ( *l->now )->name, n ) ;
        ( *l->now )->age = a ;
        ( *l->now )->sex = s ;
        ( *l->now )->gpa = g ;
    }
}

void EditData( LinkedList *l1 ) ;
void AddData( LinkedList *l1 ) ;
void FindData( LinkedList *l1 ) ;
void readfile( LinkedList *l1 ) ;
void writefile( LinkedList *l1 ) ;

int main() {
    LinkedList listA ;
    initList( &listA ) ;
    int menu ;
    readfile( &listA ) ;
    
    printf( "      Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ) ;
    scanf( "%d", &menu ) ;
    
    while( menu != 0 ) {
        switch( menu ) {
            case 1 : 
                AddData( &listA ) ; 
                break ;
            case 2 : 
                EditData( &listA ) ; 
                break ;
            case 3 : 
                {
                    char n[ 20 ] ;
                    printf( "Enter Name to Delete: " ) ;
                    scanf( "%s", n ) ;
                    if ( FindNode( &listA, n ) ) {
                        DelNode( &listA ) ;
                        printf( "Deleted.\n" ) ;
                    } else {
                        printf( "Data not found.\n" ) ;
                    }
                }
                break ;
            case 4 : 
                FindData( &listA ) ; 
                break ;
            case 5 : 
                ShowAll( &listA ) ; 
                break ;
        }
        printf( "      Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ) ;
        scanf( "%d", &menu ) ;
    }
    
    writefile( &listA ) ;
    return 0 ;
}

void AddData( LinkedList *l1 ) {
    char n[ 20 ], s ;
    int a ;
    float g ;
    printf( "Name: " ) ; scanf( "%s", n ) ;
    printf( "Age: " ) ; scanf( "%d", &a ) ;
    printf( "Sex: " ) ; scanf( " %c", &s ) ;
    printf( "GPA: " ) ; scanf( "%f", &g ) ;
    GoLast( l1 ) ;
    InsNode( l1, n, a, s, g ) ;
}

void EditData( LinkedList *l1 ) {
    char n[ 20 ], s ;
    int a ;
    float g ;
    printf( "Enter Name to Edit: " ) ;
    scanf( "%s", n ) ;
    if ( FindNode( l1, n ) ) {
        printf( "New Age: " ) ; scanf( "%d", &a ) ;
        printf( "New Sex: " ) ; scanf( " %c", &s ) ;
        printf( "New GPA: " ) ; scanf( "%f", &g ) ;
        EditNode( l1, n, a, s, g ) ;
    } else {
        printf( "Data not found.\n" ) ;
    }
}

void FindData( LinkedList *l1 ) {
    char n[ 20 ] ;
    printf( "Enter Name to Find: " ) ;
    scanf( "%s", n ) ;
    if ( FindNode( l1, n ) ) {
        struct studentNode *node = NowNode( l1 ) ;
        printf( "Found -> Age: %d, Sex: %c, GPA: %.2f\n", node->age, node->sex, node->gpa ) ;
    } else {
        printf( "Data not found.\n" ) ;
    }
}

void readfile( LinkedList *l1 ) {
    FILE *fp = fopen( "student.bin", "rb" ) ;
    if ( fp == NULL ) return ;
    struct {
        char name[ 20 ] ;
        int age ;
        char sex ;
        float gpa ;
    } temp ;
    while ( fread( &temp, sizeof( temp ), 1, fp ) ) {
        GoLast( l1 ) ;
        InsNode( l1, temp.name, temp.age, temp.sex, temp.gpa ) ;
    }
    fclose( fp ) ;
}

void writefile( LinkedList *l1 ) {
    FILE *fp = fopen( "student.bin", "wb" ) ;
    if ( fp == NULL ) return ;
    GoFirst( l1 ) ;
    while ( NowNode( l1 ) != NULL ) {
        struct studentNode *node = NowNode( l1 ) ;
        fwrite( node, sizeof( char ) * 20 + sizeof( int ) + sizeof( char ) + sizeof( float ), 1, fp ) ;
        GoNext( l1 ) ;
    }
    fclose( fp ) ;
}