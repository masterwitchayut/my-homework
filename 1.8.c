#include <stdio.h>

#define WORK_START 8
#define WORK_END 17
#define HOUR_MIN 0
#define HOUR_MAX 23

int main() {
    int dayCode;
    int hour;

    if (scanf("%d %d", &dayCode, &hour) != 2) {
        return 1;
    }

    /* ตรวจสอบช่วงของ hour ก่อน */
    if (hour < HOUR_MIN || hour > HOUR_MAX) {
        printf("Invalid Hour\n");
        return 0;
    }

    switch (dayCode) {

        /* วันทำงาน: จันทร์ - ศุกร์ */
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (hour >= WORK_START && hour <= WORK_END) {
                printf("System Running (Workday)\n");
            } else {
                printf("System Idle (Off-hours)\n");
            }
            break;

        /* วันหยุด: เสาร์ - อาทิตย์ */
        case 6:
        case 7:
            printf("Weekend Relax Mode\n");
            break;

        /* รหัสวันไม่ถูกต้อง */
        default:
            printf("Invalid Day Code\n");
            break;
    }

    return 0;
}
