#include <stdio.h>
#include <string.h>

// ประกาศหัวฟังก์ชันตามโจทย์
void explode(char str1[], char splitter, char str2[][10], int *count);

int main()
{
    // จองพื้นที่เก็บผลลัพธ์ตามโจทย์
    char out[20][10];

    // ประกาศตัวแปรจำนวนเต็ม (ตามที่โจทย์เขียนว่า "จำนวนเต็ม ;")
    int num = 0;

    explode("I/Love/You", '/', out, &num);

    // ลองวนลูปแสดงผลลัพธ์ดู (เพื่อให้รู้ว่าโปรแกรมทำงานถูก)
    printf("count = %d\n", num);
    for (int i = 0; i < num; i++)
    {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }

    // ส่งกลับ 0 ;
    return 0;
}

// เขียนฟังก์ชันด้านล่าง
void explode(char str1[], char splitter, char str2[][10], int *count)
{
    int i = 0;   // ตัวนับตำแหน่งของ str1
    int row = 0; // ตัวนับแถวของ str2 (คำที่เท่าไหร่)
    int col = 0; // ตัวนับตัวอักษรในแต่ละคำ

    // วนลูปจนกว่าจะเจอจุดจบของข้อความ (\0)
    while (str1[i] != '\0')
    {
        if (str1[i] == splitter)
        {
            // ถ้าเจอตัวคั่น ให้ปิดท้ายคำเดิมด้วย \0
            str2[row][col] = '\0';
            // ขยับไปคำถัดไป (แถวใหม่)
            row++;
            // รีเซ็ตตัวนับตัวอักษรเป็น 0
            col = 0;
        }
        else
        {
            str2[row][col] = str1[i];

            col++;
        }
        i++; // ขยับไปตัวถัดไปของ str1
    }

    // อย่าลืมปิดท้ายคำสุดท้ายด้วย \0 เพราะลูปจบก่อน
    str2[row][col] = '\0';

    *count = row + 1;
}