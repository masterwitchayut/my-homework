#include <stdio.h>

int main() {
    int number;

    do {
        printf("Enter a number (1-10): ");
        
        // รับค่าจากผู้ใช้
        if (scanf("%d", &number) != 1) {
            // กรณีผู้ใช้พิมพ์ตัวอักษรแทนตัวเลข
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // ล้างบัฟเฟอร์เพื่อป้องกัน loop ค้าง
            number = 0; // กำหนดค่าให้อยู่นอกช่วง 1-10 เพื่อให้ loop ทำงานต่อ
            continue;
        }

        // เงื่อนไขข้อที่ 2: ถ้าตัวเลขไม่อยู่ในช่วง 1-10 ให้แสดง Error
        if (number < 1 || number > 10) {
            printf("Error: Value must be 1-10.\n");
        }

    } while (number < 1 || number > 10); // เงื่อนไขข้อที่ 1: วนซ้ำถ้าตัวเลขน้อยกว่า 1 หรือมากกว่า 10

    // เงื่อนไขข้อที่ 3: เมื่อกรอกถูกต้องแล้ว ให้แสดงผลและจบการทำงาน
    printf("Input accepted: %d\n", number);

    return 0;
}