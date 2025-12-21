#include <stdio.h>

// ฟังก์ชันสำหรับตรวจสอบสถานะและพิมพ์ผลลัพธ์
void checkStatus(int studentId, int score, float attendance, int *passCount, int *failCount) {
    int scorePass = (score >= 50);
    int attendancePass = (attendance >= 75.0);

    printf("Student ID: %d -> ", studentId);

    if (scorePass && attendancePass) {
        printf("PASS\n");
        (*passCount)++;
    } else {
        printf("FAIL (Reason: ");
        if (!scorePass && !attendancePass) {
            printf("Both Score and Attendance");
        } else if (!scorePass) {
            printf("Score");
        } else {
            printf("Attendance");
        }
        printf(")\n");
        (*failCount)++;
    }
}

int main() {
    int N, i;
    int studentId, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0;
    int failCount = 0;

    // รับจำนวนนักเรียน
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        // รับข้อมูล 4 ค่าต่อคน
        if (scanf("%d %d %d %d", &studentId, &score, &totalClasses, &absentClasses) != 4) {
            break;
        }

        // คำนวณเปอร์เซ็นต์การเข้าเรียน
        // สูตร: ((คาบทั้งหมด - ขาด) / คาบทั้งหมด) * 100
        attendancePercent = (float)(totalClasses - absentClasses) / totalClasses * 100.0;

        // เรียกใช้ฟังก์ชันเพื่อตรวจสอบและแสดงผล
        checkStatus(studentId, score, attendancePercent, &passCount, &failCount);
    }

    // แสดงผลสรุปตอนท้าย
    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}