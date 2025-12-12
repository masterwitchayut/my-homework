#include <stdio.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 9 
#define MAX_TOKENS 20      

/*
 * ฟังก์ชัน explode: แยกสตริง str1 ออกเป็นส่วนย่อยตามตัวคั่น splitter
 * (โค้ดฟังก์ชันนี้มาจากคำตอบก่อนหน้าเพื่อให้โค้ดทำงานได้สมบูรณ์)
 */
void explode(const char str1[], char splitter, char str2[][10], int *count) {
    *count = 0;
    int str1_idx = 0;
    int char_idx = 0;

    for (str1_idx = 0; str1_idx <= strlen(str1); str1_idx++) {
        char current_char = str1[str1_idx];

        if (current_char == splitter || current_char == '\0') {
            
            // ป้องกันการนับตัวคั่นซ้ำเป็นสตริงว่างในบางกรณี (เพิ่มความแข็งแรง)
            if (char_idx == 0 && str1_idx > 0 && current_char != '\0' && str1[str1_idx - 1] == splitter) {
                continue;
            }
            if (*count >= MAX_TOKENS) {
                *count = -1; // Error code for max tokens exceeded
                return;
            }

            str2[*count][char_idx] = '\0';
            (*count)++;    
            char_idx = 0;
            
        } 
        else {
            if (char_idx >= MAX_TOKEN_LENGTH) {
                 // หากส่วนย่อยยาวเกิน ให้ละทิ้งตัวอักษรส่วนเกิน
                 // หากต้องการให้แสดงข้อผิดพลาด (num=-1) ต้องใช้ return/break 
                 continue; // ละทิ้งตัวอักษรส่วนเกินตาม Guardrail เดิม
            }
            str2[*count][char_idx] = current_char;
            char_idx++;
        }
    }
    // หากสตริงว่างเปล่า ต้องปรับ *count ให้เป็น 0 (เพราะจะถูกนับเป็น 1 ในลูป)
    if (strlen(str1) == 0 && *count == 1) {
        *count = 0;
    }
}


int main() {
    char out[20][10]; 
    int num; // ตัวแปรสำหรับเก็บจำนวนส่วนย่อย

    // **แก้ไขการเรียกใช้ฟังก์ชัน:** // ต้องส่ง 4 อาร์กิวเมนต์: str1, splitter (char), str2 (array), &count (pointer)
    explode( "I/Love/You", '/', out, &num ); 

    // เพิ่มการพิมพ์ผลลัพธ์เพื่อทดสอบการทำงาน
    printf("--- Explode Result ---\n");
    if (num > 0) {
        printf("Count: %d\n", num);
        for (int i = 0; i < num; i++) {
            printf("str2[%d] = \"%s\"\n", i, out[i]);
        }
    } else if (num == 0) {
        printf("Count: 0 (No tokens found)\n");
    } else {
        printf("Error during explosion (Code %d)\n", num);
    }

    return 0;
}