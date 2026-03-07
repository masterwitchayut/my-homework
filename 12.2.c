#include <stdio.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx );

int main() {
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x = KnapsackGreedy( w, v, n, wx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
}

int *KnapsackGreedy( int *w, int *v, int n, int wx ) {
    static int x[100];
    float ratio[100];
    int index[100];

    for (int i = 0; i < n; i++) {
        x[i] = 0;
        index[i] = i;
        ratio[i] = (float)v[i] / w[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                float tempR = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempR;

                int tempIdx = index[j];
                index[j] = index[j + 1];
                index[j + 1] = tempIdx;
            }
        }
    }

    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        int idx = index[i];
        if (currentWeight + w[idx] <= wx) {
            x[idx] = 1;
            currentWeight += w[idx];
        } else {
            x[idx] = 0;
        }
    }

    return x;
}