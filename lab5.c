#include <stdio.h>

void GetMatrix(int matrixData[], int *Rows, int *Cols)
{
    int rows; 
    int cols;
    int i; 
    int j; 
    
    printf("Enter rows (m): ");
    scanf("%d", Rows);

    rows = *Rows;

    printf("Enter cols (n): ");
    scanf("%d", Cols);

    cols = *Cols;

    if (rows <= 0 || cols <= 0 || (rows * cols) > 100) 
    {
        printf("Error: Matrix size out of bounds (Max 100 elements).\n");
        *Rows = 0;
        *Cols = 0;
        return;
    }

    printf("Enter elements (%d x %d):\n", rows, cols);

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            
            scanf("%d", &matrixData[(i * cols) + j]);
        }
    }
}

int main()
{
    // CLO3 Fix: ใช้ const int แทนตัวเลขวิเศษ 100 ในการกำหนดขนาด
    const int MAX_SIZE = 100;

    int matrixData[MAX_SIZE];
    
    int rows;
    int cols;
    int i; 
    int j;
    
    GetMatrix(matrixData, &rows, &cols);

    if (rows <= 0 || cols <= 0)
    {
        return 0;
    }

    printf("\n--- Result Matrix ---\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%4d", matrixData[(i * cols) + j]);
        }
        printf("\n");
    }

    return 0;
}