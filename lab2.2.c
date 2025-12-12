#include <stdio.h>
#include <string.h>

char *reverse(char *dest, const char str1[])
{
    // 1. ตรวจสอบความยาว
    int len = strlen(str1);

    // *Guardrail*: ตรวจสอบว่าสตริงยาวเกินกว่าที่บัฟเฟอร์จะรองรับหรือไม่
    // (สมมติว่าบัฟเฟอร์ dest มีขนาด 50 ตามที่กำหนดใน main)
    if (len >= 50)
    {
        return NULL;
    }

    // 2. ลูปสำหรับคัดลอกตัวอักษร
    int i, j;

    // i เริ่มจากตัวอักษรสุดท้ายของ str1 (len - 1)
    // j เริ่มจากตัวอักษรแรกของ dest (0)
    for (i = len - 1, j = 0; i >= 0; i--, j++)
    {
        // คัดลอกตัวอักษรจาก str1 (จากหลังไปหน้า) ไปยัง dest (จากหน้าไปหลัง)
        dest[j] = str1[i];
    }

    // 3. ปิดท้ายด้วย null terminator
    dest[len] = '\0';

    return dest;
}

int main()
{
    // ตัวอย่างที่ 1: "I Love You"
    char text[50] = "I Love You";
    char out_buffer[50]; // บัฟเฟอร์สำหรับผลลัพธ์แรก (ขนาด 50 ตามที่ฟังก์ชัน reverse ตรวจสอบ)

    // เรียกใช้ฟังก์ชัน: reverse(บัฟเฟอร์, สตริงต้นฉบับ)
    char *out = reverse(out_buffer, text);

    printf("Input: \"%s\"\n", text);
    if (out != NULL)
    {
        printf("Output: \"%s\"\n\n", out); // ผลลัพธ์: "uoY evoL I"
    }
    else
    {
        printf("Error: Input string too long.\n\n");
    }

    // ---

    // ตัวอย่างที่ 2: "Hello World"
    char text2[50] = "Hello World";
    char out2_buffer[50]; // บัฟเฟอร์สำหรับผลลัพธ์ที่สอง
    char *out2 = reverse(out2_buffer, text2);

    printf("Input: \"%s\"\n", text2);
    if (out2 != NULL)
    {
        printf("Output: \"%s\"\n", out2); // ผลลัพธ์: "dlroW olleH"
    }
    else
    {
        printf("Error: Input string too long.\n");
    }

    return 0;
}