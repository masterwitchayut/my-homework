#include <stdio.h>

void deposit(float *balance, float amount);
void withdraw(float *balance, float amount, float penaltyFee, float *totalPenalties);
void calculateInterest(float *balance);

int main() {
    int N_PERIODS, cmdCode, i;
    float initialBalance, PENALTY_FEE, amount;
    float currentBalance;
    float totalPenalties = 0.0;

    if (scanf("%f %f %d", &initialBalance, &PENALTY_FEE, &N_PERIODS) != 3) {
        return 1;
    }

    currentBalance = initialBalance;
    printf("Starting Balance: %.2f\n", initialBalance);

    for (i = 1; i <= N_PERIODS; i++) {
        if (scanf("%d %f", &cmdCode, &amount) != 2) {
            break;
        }

        printf("--- Month %d ---\n", i);

        switch (cmdCode) {
            case 1:
                deposit(&currentBalance, amount);
                printf("Deposit: %.2f\n", amount);
                break;

            case 2:
                withdraw(&currentBalance, amount, PENALTY_FEE, &totalPenalties);
                break;

            case 3:
                calculateInterest(&currentBalance);
                break;

            default:
                printf("Error: Invalid Command\n");
        }
    }

    printf("Final Balance: %.2f\n", currentBalance);
    printf("Total Penalties: %.2f\n", totalPenalties);

    return 0;
}

void deposit(float *balance, float amount) {
    *balance = *balance + amount;
}

void withdraw(float *balance, float amount, float penaltyFee, float *totalPenalties) {
    if (amount <= *balance) {
        *balance = *balance - amount;
        printf("Withdrawal: %.2f\n", amount);
    } else {
        *balance = *balance - penaltyFee;
        *totalPenalties = *totalPenalties + penaltyFee;
        printf("WITHDRAWAL FAILED. Penalty (%.2f) applied\n", penaltyFee);
    }
}

void calculateInterest(float *balance) {
    float APR, interest;

    if (*balance < 1000.0) {
        APR = 1.0;
    } else {
        APR = 2.5;
    }

    interest = (*balance) * (APR / 100.0) / 12.0;
    *balance = *balance + interest;

    printf("Interest: %.2f (Rate: %.1f%%)\n", interest, APR);
}
