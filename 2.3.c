#include <stdio.h>
#include <string.h>

/*
 * ฟังก์ชัน explode: แยกสตริง str1 ออกเป็นส่วนย่อยตามตัวคั่น splitter
 *
 * พารามิเตอร์:
 * - str1: สตริงต้นฉบับที่ต้องการแยก (จะไม่ถูกแก้ไข)
 * - splitter: ตัวอักขระที่ใช้เป็นตัวคั่น
 * - str2[][10]: อาร์เรย์สองมิติสำหรับเก็บผลลัพธ์ (แต่ละส่วนย่อยมีความยาวไม่เกิน 9 + '\0')
 * - count: พอยน์เตอร์ไปยังตัวแปร int เพื่อเก็บจำนวนส่วนย่อยที่แยกได้
 */
void explode(const char str1[], char splitter, char str2[][10], int *count)
{
    // กำหนดให้ตัวนับส่วนย่อยเริ่มต้นเป็น 0
    *count = 0;

    // index ใน str1 ที่เรากำลังอ่านอยู่
    int str1_idx = 0;

    // index ใน str2[token_idx] ที่เรากำลังเขียนอยู่
    int char_idx = 0;

    // วนลูปอ่านทุกตัวอักษรใน str1
    for (str1_idx = 0; str1_idx <= strlen(str1); str1_idx++)
    {

        // อ่านตัวอักษรปัจจุบัน
        char current_char = str1[str1_idx];

        // ตรวจสอบเงื่อนไขการหยุด/คั่น:
        // 1. ถ้าเจอตัวคั่น (splitter) หรือ
        // 2. ถ้าเจอตัวจบสตริง ('\0') (แปลว่าอ่านถึงส่วนสุดท้ายแล้ว)
        if (current_char == splitter || current_char == '\0')
        {

            // 1. ปิดท้ายสตริงย่อยปัจจุบันด้วย null terminator
            str2[*count][char_idx] = '\0';

            // 2. เตรียมตัวสำหรับส่วนย่อยถัดไป
            (*count)++;   // นับเพิ่มจำนวนส่วนย่อยที่แยกได้
            char_idx = 0; // รีเซ็ต index ตัวอักษรสำหรับส่วนย่อยใหม่

            // **Guardrail 1: ตรวจสอบว่าจำนวนส่วนย่อยเกิน 20 หรือยัง**
            if (*count >= 20)
            {
                // ถ้าเกิน 20 ก็หยุดทำงาน
                break;
            }
        }
        else
        {
            // ถ้ายังไม่เจอตัวคั่น ให้คัดลอกตัวอักษร

            // **Guardrail 2: ตรวจสอบว่าความยาวของส่วนย่อยเกิน 9 หรือยัง**
            if (char_idx < 9)
            { // 9 คือ Max Length - 1 (เผื่อ '\0')
                str2[*count][char_idx] = current_char;
                char_idx++;
            }
            // ถ้าเกิน 9 จะถูกละทิ้ง (และจะไม่นำไปรวมในผลลัพธ์)
        }
    }
}

int main()
{
    // อาร์เรย์สำหรับเก็บผลลัพธ์: 20 แถว, แต่ละแถวยาว 10 ตัวอักษร
    char out[20][10];
    int num; // ตัวแปรสำหรับเก็บจำนวนส่วนย่อย

    // **กรณีทดสอบที่ 1: ตามตัวอย่าง (I/Love/You)**
    printf("--- Test Case: I/Love/You ---\n");
    explode("I/Love/You", '/', out, &num);

    printf("Count: %d\n", num);
    for (int i = 0; i < num; i++)
    {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }

    // **กรณีทดสอบที่ 2: ตัวคั่นอื่น (A-B-C-D)**
    printf("\n--- Test Case: A-B-C-D ---\n");
    explode("A-B-C-D", '-', out, &num);

    printf("Count: %d\n", num);
    for (int i = 0; i < num; i++)
    {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }

    return 0;
}