#include <stdio.h>

int main() {
    int categoryCode;
    float price_before_vat;
    float totalBill = 0.0;
    float vatAmount = 0.0;
    float vatRate = 0.0;

    /* รับข้อมูลราคาก่อนภาษี และรหัสหมวดหมู่ */
    if (scanf("%f %d", &price_before_vat, &categoryCode) != 2) {
        return 1;
    }

    /* กำหนดอัตรา VAT ตามหมวดหมู่ */
    if (categoryCode == 1) {
        vatRate = 0.07;
    }
    else if (categoryCode == 2) {
        vatRate = 0.00;
    }
    else if (categoryCode == 3) {
        vatRate = 0.15;
    }
    else {
        printf("Invalid Category\n");
        printf("Total Price: 0.00\n");
        return 0;
    }

    /* คำนวณ VAT และราคาสุทธิ */
    vatAmount = price_before_vat * vatRate;
    totalBill = price_before_vat + vatAmount;

    printf("VAT Amount: %.2f\n", vatAmount);
    printf("Total Price: %.2f\n", totalBill);

    return 0;
}
