#include <stdio.h>

float calculateDailySpend(float remainingBudget) {
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

int main() {
    int N_DAYS, day;
    float initialBudget;
    float remainingBudget;
    float dailySpend;

    if (scanf("%f %d", &initialBudget, &N_DAYS) != 2) {
        return 1;
    }

    remainingBudget = initialBudget;

    printf("Day | Spend | Remaining\n");
    printf("---------------------------\n");

    for (day = 1; day <= N_DAYS; day++) {
        dailySpend = calculateDailySpend(remainingBudget);

        if (dailySpend > remainingBudget) {
            dailySpend = remainingBudget;
        }

        remainingBudget -= dailySpend;
        printf("%d | %.2f | %.2f\n", day, dailySpend, remainingBudget);
    }

    printf("---------------------------\n");
    printf("Final Budget: %.2f\n", remainingBudget);

    return 0;
}