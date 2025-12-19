#include <stdio.h>

int main() {
    int zoneCode;
    float weight_kg;
    float totalCost = 0.0;

    // รับข้อมูล zoneCode และ weight_kg
    if (scanf("%d %f", &zoneCode, &weight_kg) != 2) {
        return 1;
    }

    // ใช้ switch ในการตรวจสอบ zoneCode
    switch (zoneCode) {
        case 1: // Local
            if (weight_kg <= 5) {
                totalCost = 50.0;
            } else {
                totalCost = 80.0;
            }
            break;

        case 2: // Regional
            if (weight_kg <= 10) {
                totalCost = 150.0;
            } else {
                totalCost = 250.0;
            }
            break;

        case 3: // International
            totalCost = 500.0;
            break;

        default:
            printf("Invalid Zone Code\n");
            return 0; // จบการทำงานทันทีถ้า zone ไม่ถูกต้อง
    }

    // แสดงผลลัพธ์ Total Cost (เฉพาะกรณีที่คำนวณค่าได้ถูกต้อง)
    if (totalCost > 0.0) {
        printf("%.2f\n", totalCost);
    }

    return 0;
}