#include <stdio.h>
#include <string.h>

void explode(char str1[], char str2[][50], char splitter, int *count)
{
    int i = 0;
    int row = 0;
    int col = 0;

    while (str1[i] != '\0')
    {
        if (str1[i] == splitter)
        {
            str2[row][col] = '\0';
            row++;
            col = 0;
        }
        else
        {
            str2[row][col] = str1[i];
            col++;
        }
        i++;
    }

    str2[row][col] = '\0';

    *count = row + 1;
}

int main()
{
    char str1[] = "I/Love/You";
    char splitter = '/';

    char str2[10][50];
    int count = 0;

    explode(str1, str2, splitter, &count);

    for (int k = 0; k < count; k++)
    {
        printf("str2[%d] = \"%s\"\n", k, str2[k]);
    }

    printf("\ncount = %d\n", count);

    return 0;
}