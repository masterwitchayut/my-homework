#include <stdio.h>

void calculate_division(int dividend, int divisor, int *quotient, int *remainder);

int main() {
    int num1, num2, q, r;

    scanf("%d", &num1);
    scanf("%d", &num2);

    if (num2 != 0) {
        calculate_division(num1, num2, &q, &r);

        printf("\n--- DIVISION REPORT ---\n");
        printf("Dividend: %d\n", num1);
        printf("Divisor: %d\n", num2);
        printf("Quotient: %d\n", q);
        printf("Remainder: %d\n", r);
    } else {
        printf("\nError: Division by zero is not allowed.\n");
    }

    return 0;
}

void calculate_division(int dividend, int divisor, int *quotient, int *remainder) {
    *quotient = dividend / divisor;
    *remainder = dividend % divisor;
}