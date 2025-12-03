    #include <stdio.h>

    int GetSet(int data[]);

    int main()
    {
        int data[100];
        int num;

        num = GetSet(data);

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

    int GetSet(int data[])
    {
        int N;

        printf("Enter N (max 100): ");
        if (scanf("%d", &N) != 1 || N <= 0 || N > 100)
        {
            return 0;
        }

        printf("Enter %d integers:\n", N);
        for (int i = 0; i < N; i++)
        {

            if (scanf("%d", &data[i]) != 1)
            {
                N = i;
                break;
            }
        }

        return N;
    }