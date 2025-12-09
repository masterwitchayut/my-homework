#include <stdio.h>
#include <string.h>

char *reverse(char str1[])
{

    static char reversed_buffer[50];
    int len = strlen(str1);

    if (len >= 50)
    {

        return NULL;
    }

    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++)
    {
        reversed_buffer[j] = str1[i];
    }

    reversed_buffer[len] = '\0';

    return reversed_buffer;
}

int main()
{
    char text[50] = "I Love You";
    char *out = reverse(text);

    printf("Input: \"%s\"\n", text);
    if (out != NULL)
    {
        printf("Output: \"%s\"\n\n", out);
    }
    else
    {
        printf("Error: Input string too long.\n\n");
    }

    char text2[50] = "Hello World";
    char *out2 = reverse(text2);

    printf("Input: \"%s\"\n", text2);
    if (out2 != NULL)
    {
        printf("Output: \"%s\"\n", out2);
    }
    else
    {
        printf("Error: Input string too long.\n");
    }

    return 0;
}