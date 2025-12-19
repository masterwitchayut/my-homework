#include <stdio.h>

int main() {
    int customerType;
    float consumption_kWh;
    float totalBill = 0.0;

    /* รับข้อมูล */
    if (scanf("%d %f", &customerType, &consumption_kWh) != 2) {
        return 1;
    }

    /* ตรวจสอบประเภทลูกค้า */
    if (customerType == 1) {
        /* Customer Type 1 : ครัวเรือน */
        if (consumption_kWh <= 100) {
            totalBill = consumption_kWh * 3.0;
        } else {
            totalBill = consumption_kWh * 4.0;
        }

        printf("%.2f\n", totalBill);

    } else if (customerType == 2) {
        /* Customer Type 2 : ธุรกิจ */
        if (consumption_kWh <= 500) {
            totalBill = consumption_kWh * 5.0;
        } else {
            totalBill = consumption_kWh * 6.5;
        }

        printf("%.2f\n", totalBill);

    } else {
        /* ประเภทลูกค้าไม่ถูกต้อง */
        printf("Invalid Customer Type\n");
    }

    return 0;
}
