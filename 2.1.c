#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[])
{
    int len = strlen(str1);
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++)
    {
        str2[j] = str1[i];
    }

    str2[len] = '\0';
}

int main()
{
    char text[50] = "I Love You";
    char out[50];
    reverse(text, out);
    printf("Input: \"%s\"\n", text);
    printf("Output: \"%s\"\n\n", out);

    char text2[50] = "Hello World";
    char out2[50];
    reverse(text2, out2);
    printf("Input: \"%s\"\n", text2);
    printf("Output: \"%s\"\n", out2);

    return 0;
}