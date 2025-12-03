#include <stdio.h>

void GetSet(int arr[], int *num);

int main() {
    int data[100];
    int num;
    
    GetSet(data, &num);

    printf("\nNumber of elements (N): %d\n", num);
    printf("Elements: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}

void GetSet(int arr[], int *num) {
    int N;
    
    printf("Enter number of elements (max 100): ");
    if (scanf("%d", &N) != 1 || N <= 0 || N > 100) {
        *num = 0;
        printf("Invalid or out of range N. Operation stopped.\n");
        return;
    }
    
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
             printf("Invalid input detected. Stopping input.\n");
             N = i;
             break;
        }
    }
    
    *num = N;
}