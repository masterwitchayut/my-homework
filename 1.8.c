#include <stdio.h>

int main() {
    int dayCode, hour;

    // รับข้อมูล dayCode และ hour
    if (scanf("%d %d", &dayCode, &hour) != 2) {
        return 1;
    }

    // ใช้ switch ตรวจสอบ dayCode เป็นหลัก
    switch (dayCode) {
        // กรณีวันจันทร์ถึงศุกร์ (1-5)
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (hour >= 8 && hour <= 17) {
                printf("System Running (Workday)\n");
            } else {
                printf("System Idle (Off-hours)\n");
            }
            break;

        // กรณีวันเสาร์และอาทิตย์ (6-7)
        case 6:
        case 7:
            printf("Weekend Relax Mode\n");
            break;

        // กรณีอื่นๆ ที่ไม่ใช่ 1-7
        default:
            printf("Invalid Day Code\n");
            break;
    }

    return 0;
}