#include <stdio.h>

int main() {
    int N_MONTHS;
    int month;
    int successCount = 0;
    float dailyDeposit;
    float monthlyTotal;

    if (scanf("%d", &N_MONTHS) != 1) {
        return 1;
    }

    for (month = 1; month <= N_MONTHS; month++) {
        monthlyTotal = 0.0;

        if (scanf("%f", &dailyDeposit) != 1) {
            break;
        }

        while (dailyDeposit != 0.00) {
            monthlyTotal = monthlyTotal + dailyDeposit;

            if (scanf("%f", &dailyDeposit) != 1) {
                break;
            }
        }

        if (monthlyTotal >= 500.00) {
            successCount++;
        }

        printf("Month %d Total: %.2f\n", month, monthlyTotal);
    }

    printf("Success Count: %d\n", successCount);

    return 0;
}
