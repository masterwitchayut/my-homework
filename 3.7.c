#include <stdio.h>

struct SalesRecord {
    char name[50];
    float target;
    float actual;
};

int main() {
    int N, i;
    float grandTotalCommission = 0.0;

    // รับจำนวนพนักงาน
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct SalesRecord records[N];

    for (i = 0; i < N; i++) {
        float baseCommission;

        // รับข้อมูล name, target, actual
        if (scanf("%s %f %f",
                  records[i].name,
                  &records[i].target,
                  &records[i].actual) != 3) {
            return 1;
        }

        // ค่าคอมมิชชั่นพื้นฐาน 10% ของยอดขายจริง
        baseCommission = records[i].actual * 0.10;

        // กรณีทำยอดเกิน 120% ของเป้า
        if (records[i].actual > records[i].target * 1.20) {
            baseCommission += 200.0;
        }
        // กรณีทำยอดถึงเป้าแต่ไม่เกิน 120%
        else if (records[i].actual >= records[i].target) {
            baseCommission += 50.0;
        }
        // กรณีทำยอดต่ำกว่า 90% ของเป้า
        else if (records[i].actual < records[i].target * 0.90) {
            baseCommission -= 100.0;
        }

        // จำกัดค่าคอมมิชชั่นสูงสุดไม่เกิน 999.99
        if (baseCommission > 999.99) {
            baseCommission = 999.99;
        }

        // รวมค่าคอมมิชชั่นทั้งหมด
        grandTotalCommission += baseCommission;
    }

    // แสดงผลลัพธ์
    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}
