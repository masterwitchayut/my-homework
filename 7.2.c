#include <stdio.h>

void calculate_investment(float principal, float rate, int years, float *interest, float *total);

int main() {
    float principal, rate, interest_earned, total_balance;
    int years;

    scanf("%f", &principal);
    scanf("%f", &rate);
    scanf("%d", &years);

    calculate_investment(principal, rate, years, &interest_earned, &total_balance);

    printf("\n--- INVESTMENT GROWTH REPORT ---\n");
    printf("Principal: %.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", rate);
    printf("Duration: %d years\n", years);
    printf("Interest Earned: %.2f\n", interest_earned);
    printf("Total Balance: %.2f\n", total_balance);

    return 0;
}

void calculate_investment(float principal, float rate, int years, float *interest, float *total) {
    *interest = principal * (rate / 100) * years;
    *total = principal + *interest;
}