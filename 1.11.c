#include <stdio.h>

int main() {
    int categoryCode;
    float price_before_vat;
    float vatRate;
    float vatAmount;
    float totalBill;

    vatRate = 0.0;
    vatAmount = 0.0;
    totalBill = 0.0;

    if (scanf("%f %d", &price_before_vat, &categoryCode) != 2) {
        return 1;
    }

    /* กำหนดอัตรา VAT ตามหมวดหมู่ */
    switch (categoryCode) {
        case 1:
            vatRate = 0.07;
            break;

        case 2:
            vatRate = 0.00;
            break;

        case 3:
            vatRate = 0.15;
            break;

        default:
            printf("Invalid Category\n");
            printf("Total Price: 0.00\n");
            return 0;
    }

    /* คำนวณ VAT และราคารวม */
    vatAmount = price_before_vat * vatRate;
    totalBill = price_before_vat + vatAmount;

    printf("VAT Amount: %.2f\n", vatAmount);
    printf("Total Price: %.2f\n", totalBill);

    return 0;
}
