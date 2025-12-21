#include <stdio.h>

int main() {
    int N_MONTHS;
    float dailyDeposit;
    float monthlyTotal;
    int successCount = 0;

    // 1. รับจำนวนเดือนที่ต้องการคำนวณ
    printf("Enter number of months: ");
    scanf("%d", &N_MONTHS);

    // 2. วนลูปตามจำนวนเดือน (Loop นอก)
    for (int i = 1; i <= N_MONTHS; i++) {
        monthlyTotal = 0; // รีเซ็ตยอดรวมของเดือนใหม่ทุกครั้ง
        printf("\n--- Month %d ---\n", i);

        // 3. วนลูปรับค่าเงินฝากรายวันจนกว่าจะเจอ 0 (Loop ใน)
        while (1) {
            printf("Enter daily deposit (0 to finish month): ");
            scanf("%f", &dailyDeposit);

            if (dailyDeposit == 0) {
                break; // หยุดรับค่าของเดือนนี้
            }
            monthlyTotal += dailyDeposit; // สะสมยอดเงินฝาก
        }

        // แสดงผลรวมรายเดือน
        printf("Total for month %d: %.2f Baht\n", i, monthlyTotal);

        // ตรวจสอบเงื่อนไขเป้าหมาย 500 บาท
        if (monthlyTotal >= 500.00) {
            successCount++;
        }
    }

    // แสดงผลสรุปจำนวนเดือนที่ทำสำเร็จ
    printf("\n============================\n");
    printf("Total successful months: %d\n", successCount);
    printf("============================\n");

    return 0;
}