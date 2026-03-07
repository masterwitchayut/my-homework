#include <stdio.h>

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x );

int main() {
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x, vx ;
    int sol[ 5 ] = { 0 } ;
    x = sol ;
    vx = KnapsackBT( w, v, n, wx, 0, x ) ;
    printf( "Value = %d\n", vx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
}

int max_val = 0;
int best_x[100];

void findSolution(int *w, int *v, int n, int wx, int i, int current_w, int current_v, int *x) {
    if (i == n) {
        if (current_v > max_val) {
            max_val = current_v;
            for (int k = 0; k < n; k++) best_x[k] = x[k];
        }
        return;
    }

    if (current_w + w[i] <= wx) {
        x[i] = 1;
        findSolution(w, v, n, wx, i + 1, current_w + w[i], current_v + v[i], x);
    }

    x[i] = 0;
    findSolution(w, v, n, wx, i + 1, current_w, current_v, x);
}

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) {
    max_val = 0;
    int temp_x[100] = {0};
    
    findSolution(w, v, n, wx, 0, 0, 0, temp_x);
    
    for (int k = 0; k < n; k++) {
        x[k] = best_x[k];
    }
    
    return max_val;
}