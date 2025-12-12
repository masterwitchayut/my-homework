#include <stdio.h>
#include <string.h>

char *reverse(char *dest, const char str1[])
{
    int len = strlen(str1);

    if (len >= 50)
    {
        return NULL;
    }

    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++)
    {
        dest[j] = str1[i]; // คัดลอกตัวอักษรจาก str1 ไปยัง dest ในลำดับย้อนกลับ
    }

    dest[len] = '\0'; // ปิดท้ายด้วย Null-terminator

    return dest;
}

int main()
{
    char text[50] = "I Love You";
    char out_buffer[50]; // บัฟเฟอร์สำหรับผลลัพธ์แรก
    char *out = reverse(out_buffer, text);

    printf("Input: \"%s\"\n", text);
    if (out != NULL)
    {
        printf("Output: \"%s\"\n\n", out); // Output: "uoY evoL I"
    }
    else
    {
        printf("Error: Input string too long.\n\n");
    }

    char text2[50] = "Hello World";
    char out2_buffer[50]; // บัฟเฟอร์สำหรับผลลัพธ์ที่สอง
    char *out2 = reverse(out2_buffer, text2);

    printf("Input: \"%s\"\n", text2);
    if (out2 != NULL)
    {
        printf("Output: \"%s\"\n", out2); // Output: "dlroW olleH"
    }
    else
    {
        printf("Error: Input string too long.\n");
    }

    return 0;
}