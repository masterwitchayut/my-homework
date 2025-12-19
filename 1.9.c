#include <stdio.h>

int main() {
    int zoneCode;
    float weight_kg;
    float totalCost = 0.0;

    if (scanf("%d %f", &zoneCode, &weight_kg) != 2) {
        return 1;
    }

    switch (zoneCode) {

        /* Zone 1 : Local */
        case 1:
            if (weight_kg <= 5.0) {
                totalCost = 50.0;
            } else {
                totalCost = 80.0;
            }
            break;

        /* Zone 2 : Regional */
        case 2:
            if (weight_kg <= 10.0) {
                totalCost = 150.0;
            } else {
                totalCost = 250.0;
            }
            break;

        /* Zone 3 : International */
        case 3:
            totalCost = 500.0;
            break;

        /* Zone Code ไม่ถูกต้อง */
        default:
            printf("Invalid Zone Code\n");
            break;
    }

    if (totalCost > 0.0 || zoneCode > 3 || zoneCode < 1) {
        printf("%.2f\n", totalCost);
    }

    return 0;
}
