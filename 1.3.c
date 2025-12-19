#include <stdio.h>

int main() {
    int num1, num2, operationCode, result;

    // ส่วนที่รับค่า
    if (scanf("%d %d %d", &num1, &num2, &operationCode) != 3) {
        return 1;
    }

    // ใช้ switch ตรวจสอบ operationCode ตามเงื่อนไข 1-5
    switch (operationCode) {
        case 1:
            result = num1 + num2;
            printf("%d", result);
            break;
        case 2:
            result = num1 - num2;
            printf("%d", result);
            break;
        case 3:
            result = num1 * num2;
            printf("%d", result);
            break;
        case 4:
            result = num1 / num2;
            printf("%d", result);
            break;
        default:
            printf("Invalid Operation");
            break;
    }

    return 0;
}