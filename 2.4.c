#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main()
{
    // 1. ประกาศตัวแปร
    char out[20][10]; // เก็บผลลัพธ์ (สูงสุด 20 คำ, คำละไม่เกิน 10 ตัวอักษร)
    int num = 0;      // เก็บจำนวนคำที่ตัดได้

    // 2. เรียกใช้งานฟังก์ชัน
    // Input: "I/Love/You", ตัวตัด: '/'
    explode("I/Love/You", '/', out, &num);

    // 3. แสดงผลลัพธ์
    printf("Total words: %d\n", num);
    printf("--------------------\n");

    for (int i = 0; i < num; i++)
    {
        printf("Word %d: \"%s\"\n", i + 1, out[i]);
    }

    return 0;
}

// --- Function Definition ---
void explode(char str1[], char splitter, char str2[][10], int *count)
{
    int idx = 0;      // ตำแหน่งตัวอักษรใน str1 (Source)
    int word_idx = 0; // ดัชนีของคำใน str2 (Row)
    int char_idx = 0; // ดัชนีตัวอักษรของคำปัจจุบัน (Col)

    // วนลูปจนกว่าจะเจอจุดจบของ String (\0)
    while (str1[idx] != '\0')
    {

        if (str1[idx] == splitter)
        {
            str2[word_idx][char_idx] = '\0';

            // ขยับไปคำถัดไป (บรรทัดใหม่) และรีเซ็ตตำแหน่งตัวอักษร
            word_idx++;
            char_idx = 0;
        }
        else
        {
            str2[word_idx][char_idx] = str1[idx];

            // ขยับตำแหน่งตัวอักษรไปตัวถัดไป
            char_idx++;
        }

        // ขยับ index ของข้อความต้นฉบับ
        idx++;
    }

    // เมื่อจบลูป ต้องปิดท้ายคำสุดท้ายด้วย \0 เสมอ (เพราะลูปจบก่อนจะได้ใส่)
    str2[word_idx][char_idx] = '\0';

    // ส่งค่าจำนวนคำกลับไป (Index เริ่มที่ 0 จึงต้อง +1)
    *count = word_idx + 1;
}