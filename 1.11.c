#include <stdio.h>

#define VAT_STANDARD 1.07
#define VAT_ZERO     1.00
#define VAT_LUXURY   1.15

int main() {
    int categoryCode;
    float price_before_vat;
    float totalBill = 0.0;
    float vatAmount = 0.0;

    /* รับข้อมูลราคาก่อนภาษี และรหัสหมวดหมู่ */
    if (scanf("%f %d", &price_before_vat, &categoryCode) != 2) {
        return 1;
    }

    /* คำนวณราคาสุทธิตามหมวดหมู่ */
    if (categoryCode == 1) {
        totalBill = price_before_vat * VAT_STANDARD;
    }
    else if (categoryCode == 2) {
        totalBill = price_before_vat * VAT_ZERO;
    }
    else if (categoryCode == 3) {
        totalBill = price_before_vat * VAT_LUXURY;
    }
    else {
        totalBill = 0.0;
    }

    /* แสดงผลลัพธ์ */
    if (categoryCode >= 1 && categoryCode <= 3) {
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
