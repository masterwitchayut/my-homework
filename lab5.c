#include <stdio.h>

void GetMatrix(int value[], int *row, int *col)
{
    int m, n;

    printf("Enter rows (m): ");
    scanf("%d", row);
    m = *row;

    printf("Enter cols (n): ");
    scanf("%d", col);
    n = *col;

    printf("Enter elements (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int index = i * n + j;

            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &value[index]);
        }
    }
}

int main()
{
    int data[100];
    int m, n;

    GetMatrix(data, &m, &n);

    if (m > 0 && n > 0 && m * n <= 100)
    {
        printf("\n--- Result Matrix ---\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%4d", data[i * n + j]);
            }
            printf("\n");
        }
    }

    return 0;
}