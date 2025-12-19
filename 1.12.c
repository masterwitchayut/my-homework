#include <stdio.h>

int main() {
    int planCode;
    float dataUsage_GB;
    float totalBill = 0.0;

    if (scanf("%d %f", &planCode, &dataUsage_GB) != 2) {
        return 1;
    }

    if (planCode == 1) {
        totalBill = 299.0;

        if (dataUsage_GB > 10.0) {
            totalBill = totalBill + 10.0 * (dataUsage_GB - 10.0);
        }
    }
    else if (planCode == 2) {
        totalBill = 599.0;

        if (dataUsage_GB > 20.0) {
            totalBill = totalBill + 50.0;
            totalBill = totalBill + 5.0 * (dataUsage_GB - 20.0);
        }
    }

    if (planCode == 1 || planCode == 2) {
        printf("%.2f\n", totalBill);
    }
    else {
        printf("Invalid Plan Code\n");
    }

    return 0;
}
