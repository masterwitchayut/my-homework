#include <stdio.h>

int main() {
    // ประกาศตัวแปรทีละบรรทัด หรือกลุ่มเล็กๆ
    int n1;
    int n2;
    int op;
    int res;

    // รับค่าตามลำดับที่โจทย์กำหนด (num1, num2, operationCode)
    // ใช้ scanf แบบพื้นฐานที่นักเรียนนิยมใช้
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &op);

    // ใช้ switch-case ตรวจสอบเงื่อนไข
    switch (op) {
        case 1:
            res = n1 + n2;
            printf("%d\n", res);
            break;

        case 2:
            res = n1 - n2;
            printf("%d\n", res);
            break;

        case 3:
            res = n1 * n2;
            printf("%d\n", res);
            break;

        case 4:
            // แก้ไข CLO4: เช็กก่อนว่าตัวหารเป็น 0 หรือไม่ เพื่อความเสถียร
            if (n2 != 0) {
                res = n1 / n2;
                printf("%d\n", res);
            } else {
                printf("Error: Division by zero\n");
            }
            break;

        default:
            // กรณีไม่ใช่เลข 1-4
            printf("Invalid Operation\n");
            break;
    }

    return 0;
}