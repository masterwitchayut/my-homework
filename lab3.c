#include <stdio.h>

int *GetSet(int *num);

int main()
{
    int N;
    int *data = GetSet(&N);

    printf("\nN: %d\n", N);

    if (N > 0)
    {
        printf("Data: ");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    return 0;
}

int *GetSet(int *num)
{
    static int data[100];
    int N;

    printf("Enter Number (1-100): ");

    if (scanf("%d", &N) != 1 || N <= 0 || N > 100)
    {
        *num = 0;
        return NULL;
    }

    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++)
    {
        if (scanf("%d", &data[i]) != 1)
        {
            *num = i;
            return data;
        }
    }

    *num = N;
    return data;
}