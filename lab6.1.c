#include <stdio.h>

void *malloc( long unsigned int size ) ;
void free( void *ptr ) ;

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
    struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **start, char name[], int age, char sex, float gpa ) ;
void InsNode( struct studentNode *now, char name[], int age, char sex, float gpa ) ;
void GoBack( struct studentNode **now ) ;
void DelNode( struct studentNode **now ) ;

int main() {
    struct studentNode *start, *now ;
    start = NULL ;

    now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
    now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
    
    GoBack( &now ) ;
    
    DelNode( &now ) ; ShowAll( start ) ;
    DelNode( &now ) ; ShowAll( start ) ;
    DelNode( &now ) ; ShowAll( start ) ;

    return 0 ;
}

void ShowAll( struct studentNode *walk ) {
    while ( walk != NULL ) {
        printf( "%s ", walk->name ) ;
        walk = walk->next ;
    }
    printf( " " ) ;
    printf( "\n" ) ;
}

struct studentNode *AddNode( struct studentNode **start, char name[], int age, char sex, float gpa ) {
    struct studentNode *newNode = ( struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    int i = 0 ;
    while ( name[ i ] != '\0' ) {
        newNode->name[ i ] = name[ i ] ;
        i++ ;
    }
    newNode->name[ i ] = '\0' ;
    newNode->age = age ;
    newNode->sex = sex ;
    newNode->gpa = gpa ;
    newNode->next = NULL ;
    newNode->back = NULL ;

    if ( *start == NULL ) {
        *start = newNode ;
    } else {
        struct studentNode *walk = *start ;
        while ( walk->next != NULL ) {
            walk = walk->next ;
        }
        walk->next = newNode ;
        newNode->back = walk ;
    }
    return newNode ;
}

void InsNode( struct studentNode *now, char name[], int age, char sex, float gpa ) {
    if ( now == NULL ) return ;
    struct studentNode *newNode = ( struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    int i = 0 ;
    while ( name[ i ] != '\0' ) {
        newNode->name[ i ] = name[ i ] ;
        i++ ;
    }
    newNode->name[ i ] = '\0' ;
    newNode->age = age ;
    newNode->sex = sex ;
    newNode->gpa = gpa ;

    newNode->next = now ;
    newNode->back = now->back ;
    if ( now->back != NULL ) {
        now->back->next = newNode ;
    }
    now->back = newNode ;
}

void GoBack( struct studentNode **now ) {
    if ( ( *now ) != NULL && ( *now )->back != NULL ) {
        ( *now ) = ( *now )->back ;
    }
}

void DelNode( struct studentNode **now ) {
    if ( *now == NULL ) return ;
    struct studentNode *delNode = *now ;
    struct studentNode *nextNode = delNode->next ;
    struct studentNode *backNode = delNode->back ;

    if ( backNode != NULL ) {
        backNode->next = nextNode ;
    }
    if ( nextNode != NULL ) {
        nextNode->back = backNode ;
    }

    if ( nextNode != NULL ) {
        *now = nextNode ;
    } else {
        *now = backNode ;
    }

    free( delNode ) ;
}