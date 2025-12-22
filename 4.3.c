#include <stdio.h>

#define DAYS 7

int main() {
    int daily_temp[DAYS];
    int max_temp;
    int i;

    // 1. รับข้อมูลอุณหภูมิ 7 วัน
    for (i = 0; i < DAYS; i++) {
        scanf("%d", &daily_temp[i]);
    }

    // 2. วิเคราะห์หาอุณหภูมิสูงสุด (Maximum Temperature)
    max_temp = daily_temp[0];
    for (i = 1; i < DAYS; i++) {
        if (daily_temp[i] > max_temp) {
            max_temp = daily_temp[i];
        }
    }

    // 3. แสดงผลลัพธ์ (Report)
    printf("\n--- DAILY TEMPERATURE REPORT ---\n");
    printf("Recorded Temperatures (C): ");
    for (i = 0; i < DAYS; i++) {
        printf("%d ", daily_temp[i]);
    }
    printf("\n");

    printf("Maximum Temperature Found: %d C\n", max_temp);

    // ตรวจสอบเงื่อนไขสรุปสภาพอากาศ
    if (max_temp >= 35) {
        printf("Weather is HOT!\n");
    } else {
        printf("Weather is MODERATE.\n");
    }

    return 0;
}