#include <stdio.h>

int main() {
    int categoryCode;
    float price_before_vat;
    float totalBill;
    float vatAmount;
    int validCategory;

    totalBill = 0.0;
    vatAmount = 0.0;
    validCategory = 1;

    if (scanf("%f %d", &price_before_vat, &categoryCode) != 2) {
        return 1;
    }

    /* คำนวณราคาสุทธิตามหมวดหมู่ */
    if (categoryCode == 1) {
        totalBill = price_before_vat + (price_before_vat * 0.07);
    }
    else if (categoryCode == 2) {
        totalBill = price_before_vat;
    }
    else if (categoryCode == 3) {
        totalBill = price_before_vat + (price_before_vat * 0.15);
    }
    else {
        totalBill = 0.0;
        validCategory = 0;
    }

    /* แสดงผลลัพธ์ */
    if (validCategory == 1) {
        vatAmount = totalBill - price_before_vat;
        printf("VAT Amount: %.2f\n", vatAmount);
        printf("Total Price: %.2f\n", totalBill);
    }
    else {
        printf("Invalid Category\n");
        printf("Total Price: %.2f\n", totalBill);
    }

    return 0;
}
