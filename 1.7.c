#include <stdio.h>

int main() {
    int customerType;
    float consumption_kWh;
    float totalBill = 0.0;

    // รับข้อมูลรหัสประเภทลูกค้า และปริมาณการใช้ไฟฟ้า
    if (scanf("%d %f", &customerType, &consumption_kWh) != 2) {
        return 1;
    }

    // ตรวจสอบรหัสลูกค้าด้วย if-else
    if (customerType == 1) {
        // Nested if-else สำหรับอัตราค่าไฟประเภทที่ 1 (ครัวเรือน)
        if (consumption_kWh <= 100) {
            totalBill = consumption_kWh * 3.0; // 0-100 kWh อัตรา 3.0 บาท
        } else {
            totalBill = consumption_kWh * 4.0; // มากกว่า 100 kWh อัตรา 4.0 บาท
        }
    } 
    else if (customerType == 2) {
        // Nested if-else สำหรับอัตราค่าไฟประเภทที่ 2 (ธุรกิจ)
        if (consumption_kWh <= 500) {
            totalBill = consumption_kWh * 5.0; // 0-500 kWh อัตรา 5.0 บาท
        } else {
            totalBill = consumption_kWh * 6.5; // มากกว่า 500 kWh อัตรา 6.5 บาท
        }
    } 
    else {
        // กรณีรหัสลูกค้าไม่ใช่ 1 หรือ 2
        printf("Invalid Customer Type\n");
        return 0;
    }

    // แสดงผลลัพธ์ค่าไฟฟ้ารวม
    if (totalBill > 0.0) {
        printf("%.2f\n", totalBill);
    }

    return 0;
}