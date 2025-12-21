#include <stdio.h>

int main() {
    int N_DAYS, day;
    float initialBudget;
    float remainingBudget;
    float dailySpend;

    // รับค่า 2 ตัว: งบประมาณเริ่มต้น และ จำนวนวัน
    printf("Enter initial budget and number of days: ");
    if (scanf("%f %d", &initialBudget, &N_DAYS) != 2) {
        return 1;
    }

    remainingBudget = initialBudget;

    // ส่วนหัวของรายงานรายวัน
    printf("Day | Spend | Remaining\n");
    printf("---------------------------\n");

    // ลูปทำงานตามจำนวนวัน N_DAYS
    for (day = 1; day <= N_DAYS; day++) {
        dailySpend = 0.0;

        // เงื่อนไขการใช้จ่ายอิงตามงบประมาณที่เหลือ
        if (remainingBudget >= 500.00) {
            dailySpend = 100.00;
        } else if (remainingBudget >= 100.00) {
            dailySpend = 50.00;
        } else if (remainingBudget > 0.0) {
            dailySpend = 20.00;
        } else {
            dailySpend = 0.0;
        }

        // กฎการหยุด: ถ้าค่าใช้จ่ายที่คำนวณได้มากกว่างบที่เหลือ ให้จ่ายเท่าที่เหลือจริง
        if (dailySpend > remainingBudget) {
            dailySpend = remainingBudget;
        }

        remainingBudget -= dailySpend;
        
        // 1. รายงานรายวัน: แสดงวัน, เงินที่ใช้จ่าย, และเงินที่เหลืออยู่
        printf("%d | %.2f | %.2f\n", day, dailySpend, remainingBudget);
    }

    // 2. รายงานสรุป: แสดงงบประมาณที่เหลืออยู่สุดท้าย (Final Budget)
    printf("---------------------------\n");
    printf("Final Budget: %.2f\n", remainingBudget);

    return 0;
}