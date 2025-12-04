#include <stdio.h>

int *GetSet(int *num);

int main()
{
    int *data;
    int num;

    data = GetSet(&num);

    printf("N: %d\n", num);

    if (num > 0)
    {
        for (int i = 0; i < num; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    return 0;
}

int *GetSet(int *num)
{
    static int data_array[100];
    int N;

    printf("Enter N (max 100): ");

    if (scanf("%d", &N) != 1 || N <= 0 || N > 100)
    {
        *num = 0;
        return NULL;
    }

    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++)
    {
        if (scanf("%d", &data_array[i]) != 1)
        {
            N = i;
            break;
        }
    }

    *num = N;

    return data_array;
}