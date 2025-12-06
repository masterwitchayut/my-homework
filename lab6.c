#include <stdio.h>

int GetMatrix(int *row, int *col) 
{
    int i;
    int n; 
    
    int a[20][20]; 

    printf("Enter row: ");
    scanf("%d", row);

    printf("Enter col: ");
    scanf("%d", col);

    if (*row <= 0 || *col <= 0 || *row > 20 || *col > 20)
    {
        printf("Error: Matrix size out of bounds (Max 20x20).\n");
        *row = 0;
        *col = 0;
        return 0;
    }

    printf("Input matrix:\n");
    for(i = 0; i < *row; i++) 
    {
        for(n = 0; n < *col; n++) 
        {
            printf("a[%d][%d] = ", i, n);
            scanf("%d", &a[i][n]);
        }
    }

    printf("\nMatrix:\n");
    for(i = 0; i < *row; i++) 
    {
        for(n = 0; n < *col; n++) 
        {
            printf("%d ", a[i][n]);
        }
        printf("\n");
    }

    return 0;
}

int main() 
{
    int m;
    int n;
    
    GetMatrix(&m, &n);
    
    return 0;
}