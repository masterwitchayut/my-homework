#include <stdio.h>

float getDailySpend(float remainingBudget) {
    if (remainingBudget >= 500.00) {
        return 100.00;
    } else if (remainingBudget >= 100.00) {
        return 50.00;
    } else if (remainingBudget > 0.0) {
        return 20.00;
    } else {
        return 0.0;
    }
}

void processBudgetTracking(float initialBudget, int N_DAYS) {
    float remainingBudget = initialBudget;
    float dailySpend;

    printf("Day | Spend | Remaining\n");
    printf("---------------------------\n");

    for (int day = 1; day <= N_DAYS; day++) {
        dailySpend = getDailySpend(remainingBudget);

        if (dailySpend > remainingBudget) {
            dailySpend = remainingBudget;
        }

        remainingBudget -= dailySpend;
        printf("%d | %.2f | %.2f\n", day, dailySpend, remainingBudget);
    }

    printf("---------------------------\n");
    printf("Final Budget: %.2f\n", remainingBudget);
}

int main() {
    int N_DAYS;
    float initialBudget;

    if (scanf("%f %d", &initialBudget, &N_DAYS) != 2) {
        return 1;
    }

    processBudgetTracking(initialBudget, N_DAYS);

    return 0;
}