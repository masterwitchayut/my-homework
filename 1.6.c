#include <stdio.h>

int main() {
    int number;

    do {
        printf("Enter a number (1-10): ");
        
        // รับค่าตัวเลขจากผู้ใช้
        if (scanf("%d", &number) != 1) {
            // ป้องกันกรณีผู้ใช้พิมพ์ตัวอักษรเพื่อให้โปรแกรมไม่ค้าง
            while(getchar() != '\n'); 
            continue;
        }

        // เงื่อนไขข้อที่ 2: ถ้าตัวเลขไม่อยู่ในช่วง 1-10 ให้แสดง Error
        if (number < 1 || number > 10) {
            printf("Error: Value must be 1-10.\n");
        }

    } while (number < 1 || number > 10); // เงื่อนไขข้อที่ 1: วนซ้ำถ้าค่าน้อยกว่า 1 หรือมากกว่า 10

    // เงื่อนไขข้อที่ 3: แสดงผลเมื่อค่าถูกต้องแล้วจบการทำงาน
    printf("Input accepted: %d\n", number);

    return 0;
}