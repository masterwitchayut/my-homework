#include <stdio.h>

struct Transaction {
    char description[50];
    float amount;
};

void updateBalances(float amount, float *income, float *expense) {
    if (amount >= 0.0) {
        *income += amount;
    } else {
        *expense += -amount;
    }
}

int main() {
    int N, i;
    float totalIncome = 0.0;
    float totalExpense = 0.0;
    float netBalance = 0.0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Transaction transactions[N];

    for (i = 0; i < N; i++) {
        if (scanf("%f %s", &transactions[i].amount, transactions[i].description) != 2) {
            return 1;
        }
        updateBalances(transactions[i].amount, &totalIncome, &totalExpense);
    }

    netBalance = totalIncome - totalExpense;

    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", netBalance);

    return 0;
}