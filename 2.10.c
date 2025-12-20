#include <stdio.h>

int main() {
    int N_PERIODS, cmdCode, i;
    float initialBalance, PENALTY_FEE, amount;
    float currentBalance;
    float totalPenalties = 0.0;
    float APR, interest;

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
            case 1: // ฝากเงิน (Deposit)
                currentBalance = currentBalance + amount;
                printf("Deposit: %.2f\n", amount);
                break;

            case 2: // ถอนเงิน (Withdrawal)
                if (amount <= currentBalance) {
                    currentBalance = currentBalance - amount;
                    printf("Withdrawal: %.2f\n", amount);
                } else {
                    // ถอนเกินยอดที่มี: คิดค่าปรับ
                    totalPenalties = totalPenalties + PENALTY_FEE;
                    printf("WITHDRAWAL FAILED. Penalty %.2f applied.\n", PENALTY_FEE);
                }
                break;

            case 3: // คิดดอกเบี้ย (Interest)
                // ใช้ Nested If-Else กำหนด APR
                if (currentBalance < 1000.00) {
                    APR = 1.0; // 1.0%
                } else {
                    APR = 2.5; // 2.5%
                }

                // คำนวณดอกเบี้ยรายเดือน (หาร 12 และหาร 100 สำหรับเปอร์เซ็นต์)
                interest = currentBalance * (APR / 100.0 / 12.0);
                currentBalance = currentBalance + interest;
                printf("Interest: %.2f (Rate: %.1f%%)\n", interest, APR);
                break;

            default: // รหัสอื่นๆ
                printf("Error: Invalid Command.\n");
                break;
        }
    }

    printf("Final Balance: %.2f\n", currentBalance);
    printf("Total Penalties: %.2f\n", totalPenalties);
    return 0;
}