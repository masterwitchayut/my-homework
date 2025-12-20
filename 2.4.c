#include <stdio.h>

int main() {
    float principal, monthlyPayment, interest;
    int monthCount = 0;
    const float INTEREST_RATE = 0.01;
    const float PENALTY = 10.0;

    if (scanf("%f %f", &principal, &monthlyPayment) != 2) {
        return 1;
    }

    while (principal > 0) {
        interest = principal * INTEREST_RATE;
        principal = principal + interest;

        if (monthlyPayment < interest) {
            principal = principal + PENALTY;
        }

        principal = principal - monthlyPayment;

        monthCount++;
        printf("Month %d: Remaining Principal = %.2f\n", monthCount, principal);
    }

    printf("Loan settled in %d months.\n", monthCount);
    return 0;
}
