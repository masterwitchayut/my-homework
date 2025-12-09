#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][10], int *count)
{
    int i = 0;
    int part_idx = 0;
    int char_idx = 0;
    *count = 0;

    while (str1[i] != '\0')
    {
        if (str1[i] == splitter)
        {

            str2[part_idx][char_idx] = '\0';

            part_idx++;
            char_idx = 0;
        }
        else
        {

            if (char_idx < 9)
            {
                str2[part_idx][char_idx] = str1[i];
                char_idx++;
            }
        }
        i++;
    }

    str2[part_idx][char_idx] = '\0';

    *count = part_idx + 1;
}

int main()
{
    char result_array[20][10];
    int num_parts;
    char input_str[] = "I/Love/You";

    printf("--- Test Case: '%s' with splitter '/'\n", input_str);
    explode(input_str, '/', result_array, &num_parts);

    for (int i = 0; i < num_parts; i++)
    {
        printf("str2[%d] = \"%s\"\n", i, result_array[i]);
    }
    printf("Final count: %d\n\n", num_parts);

    char input_edge[] = "A,B,C,D,E";
    explode(input_edge, ',', result_array, &num_parts);

    printf("--- Test Case: Edge Case '%s' with splitter ','\n", input_edge);
    for (int i = 0; i < num_parts; i++)
    {
        printf("str2[%d] = \"%s\"\n", i, result_array[i]);
    }
    printf("Final count: %d\n", num_parts);

    return 0;
}