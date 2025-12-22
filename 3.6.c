#include <stdio.h>

struct Transaction {
    char description[50];
    float amount;
};

void calculateSummary(int N, struct Transaction transactions[], float *totalIncome, float *totalExpense, float *netBalance) {
    for (int i = 0; i < N; i++) {
        if (transactions[i].amount >= 0.0) {
            *totalIncome += transactions[i].amount;
        } else {
            *totalExpense += -transactions[i].amount;
        }
    }
    *netBalance = *totalIncome - *totalExpense;
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
    }

    calculateSummary(N, transactions, &totalIncome, &totalExpense, &netBalance);

    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", netBalance);

    return 0;
}