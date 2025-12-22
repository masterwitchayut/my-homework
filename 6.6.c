#include <stdio.h>

void calculate_power(int base, int exponent, long long *result);

int main() {
    int base, exponent;
    long long result;

    scanf("%d", &base);
    scanf("%d", &exponent);

    calculate_power(base, exponent, &result);

    printf("\n--- POWER CALCULATION REPORT ---\n");
    printf("Base: %d\n", base);
    printf("Exponent: %d\n", exponent);
    printf("Result: %lld\n", result);

    return 0;
}

void calculate_power(int base, int exponent, long long *result) {
    *result = 1;
    for (int i = 0; i < exponent; i++) {
        *result *= base;
    }
}