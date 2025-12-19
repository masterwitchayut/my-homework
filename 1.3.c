#include <stdio.h>

int main() {
    int num1, num2, operationCode, result;

    if (scanf("%d %d %d", &num1, &num2, &operationCode) != 3) {
        return 1;
    }

    switch (operationCode) {
        case 1:   // บวก
            result = num1 + num2;
            printf("%d", result);
            break;

        case 2:   // ลบ
            result = num1 - num2;
            printf("%d", result);
            break;

        case 3:   // คูณ
            result = num1 * num2;
            printf("%d", result);
            break;

        case 4:   // หาร
            result = num1 / num2;
            printf("%d", result);
            break;

        default:
            printf("Invalid Operation");
    }

    return 0;
}
