#include <stdio.h>

int main() {
    int inputVal;
    int isInvalid;

    do {
        // พิมพ์ข้อความรับค่าตามโจทย์
        printf("Enter a number (1-10): ");
        
        // ตรวจสอบการรับค่าตัวเลข
        if (scanf("%d", &inputVal) != 1) {
            while(getchar() != '\n'); // ล้างบัฟเฟอร์
            isInvalid = 1; 
            continue;
        }

        // ตรวจสอบเงื่อนไขช่วง 1-10
        isInvalid = (inputVal < 1 || inputVal > 10);

        if (isInvalid) {
            // แสดง Error ตามเงื่อนไขข้อ 2
            printf("Error: Value must be 1-10.\n");
        }

    } while (isInvalid); // วนลูปตราบเท่าที่ค่าไม่ถูกต้องตามเงื่อนไขข้อ 1

    // แสดงผลสำเร็จตามเงื่อนไขข้อ 3
    printf("Input accepted: %d\n", inputVal);

    return 0;
}