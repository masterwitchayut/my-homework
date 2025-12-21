#include <stdio.h>

float calculateMonthlyTotal() {
    float dailyDeposit;
    float total = 0.0;

    if (scanf("%f", &dailyDeposit) != 1) {
        return 0.0;
    }

    while (dailyDeposit != 0.00) {
        total = total + dailyDeposit;
        if (scanf("%f", &dailyDeposit) != 1) {
            break;
        }
    }
    return total;
}

int main() {
    int N_MONTHS;
    int month;
    int successCount = 0;
    float monthlyTotal;

    if (scanf("%d", &N_MONTHS) != 1) {
        return 1;
    }

    for (month = 1; month <= N_MONTHS; month++) {
        monthlyTotal = calculateMonthlyTotal();
        
        printf("Month %d Total: %.2f\n", month, monthlyTotal);
        
        if (monthlyTotal >= 500.00) {
            successCount++;
        }
    }

    printf("Success Count: %d\n", successCount);
    return 0;
}