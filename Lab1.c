#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    if (n <= 0)
    {
        printf("error\n");
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("Hello World\n");
    }

    return 0;
}