#include <stdio.h>

void go( int ***p, int **z ) {
    *p = z ;
}

int main() {
    int val_b = 10, val_c = 20 ;
    int *b = &val_b ;
    int *c = &val_c ;
    int **a ;

    go( &a, &b ) ;
    printf( "%d %p %p %p\n", **a, *a, a, &a ) ;

    go( &a, &c ) ;
    printf( "%d %p %p %p\n", **a, *a, a, &a ) ;

    return 0 ;
}