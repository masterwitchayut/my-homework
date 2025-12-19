#include <stdio.h>

int main() {
    int N;
    int sum;
    int i;

    // กำหนดค่าเริ่มต้นให้ sum แยกบรรทัดตาม CLO3
    sum = 0;

    // รับค่า N จากผู้ใช้
    scanf("%d", &N);

    // ตรวจสอบความเสถียร (CLO4): ถ้า N น้อยกว่า 1 ให้ผลรวมเป็น 0
    if (N < 1) {
        printf("0\n");
        return 0;
    }

    // ใช้คำสั่ง for loop เพื่อหาผลรวม
    // แยกคำสั่งให้ชัดเจนเพื่อให้อ่านง่าย
    for (i = 1; i <= N; i++) {
        sum = sum + i;
    }

    // แสดงผลลัพธ์สุดท้าย
    printf("%d\n", sum);

    return 0;
}