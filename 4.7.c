#include <stdio.h>

struct SalesRecord {
    char name[50];
    float target;
    float actual;
};

float calculateCommission(struct SalesRecord record) {
    float baseCommission = record.actual * 0.10;

    if (record.actual >= record.target * 1.20) {
        baseCommission += 200.0;
    } else if (record.actual >= record.target) {
        baseCommission += 50.0;
    } else if (record.actual < record.target * 0.90) {
        baseCommission -= 100.0;
    }

    return baseCommission;
}

int main() {
    int N, i;
    float grandTotalCommission = 0.0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct SalesRecord records[N];

    for (i = 0; i < N; i++) {
        if (scanf("%f %f %s", &records[i].target, &records[i].actual, records[i].name) != 3) {
            return 1;
        }
        grandTotalCommission += calculateCommission(records[i]);
    }

    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}