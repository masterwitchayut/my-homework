#include <stdio.h>

int main() {
    int num1, num2, operationCode;

    // รับค่าจาก user ตามลำดับ: num1, num2 และ operationCode
    if (scanf("%d %d %d", &num1, &num2, &operationCode) != 3) {
        return 1;
    }

    // ใช้ switch ตรวจสอบเงื่อนไขตาม operationCode
    switch (operationCode) {
        case 1:
            printf("%d", num1 + num2);
            break;
        case 2:
            printf("%d", num1 - num2);
            break;
        case 3:
            printf("%d", num1 * num2);
            break;
        case 4:
            // ตรวจสอบเบื้องต้น: การหารด้วย 0 จะทำให้โปรแกรม error ได้
            if (num2 != 0) {
                printf("%d", num1 / num2);
            } else {
                printf("Error: Division by zero");
            }
            break;
        default:
            printf("Invalid Operation");
            break;
    }

    return 0;
}