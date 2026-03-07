#include <stdio.h>

int *KnapsackDP( int *w, int *v, int n, int wx );

int main() {
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x ;
    x = KnapsackDP( w, v, n, wx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
}

int *KnapsackDP( int *w, int *v, int n, int wx ) {
    static int x[100];
    int F[n + 1][wx + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            } else if (w[i - 1] <= j) {
                int valWith = v[i - 1] + F[i - 1][j - w[i - 1]];
                int valWithout = F[i - 1][j];
                F[i][j] = (valWith > valWithout) ? valWith : valWithout;
            } else {
                F[i][j] = F[i - 1][j];
            }
        }
    }

    int res = F[n][wx];
    int current_w = wx;
    
    for (int i = 0; i < n; i++) x[i] = 0;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res == F[i - 1][current_w]) {
            continue;
        } else {
            x[i - 1] = 1;
            res = res - v[i - 1];
            current_w = current_w - w[i - 1];
        }
    }

    return x;
}