#include <stdio.h>

int checkStudentStatus(int id, int score, float attendance) {
    printf("Student ID: %d -> ", id);

    if (score >= 50 && attendance >= 75.0) {
        printf("PASS\n");
        return 1; // ส่งค่ากลับว่าสอบผ่าน
    } else {
        printf("FAIL: ");
        if (score < 50 && attendance < 75.0) {
            printf("Both Score and Attendance\n");
        } else if (score < 50) {
            printf("Score\n");
        } else {
            printf("Attendance\n");
        }
        return 0; // ส่งค่ากลับว่าสอบตก
    }
}

int main() {
    int N, i;
    int studentId, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0;
    int failCount = 0;

    printf("Enter number of students: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("\nStudent #%d info (ID Score Total Absent): ", i + 1);
        if (scanf("%d %d %d %d", &studentId, &score, &totalClasses, &absentClasses) != 4) {
            break;
        }

        // คำนวณเปอร์เซ็นต์การเข้าเรียน
        attendancePercent = (float)(totalClasses - absentClasses) / totalClasses * 100.0;

        // เรียกใช้ฟังก์ชัน และสะสมแต้ม Pass/Fail
        if (checkStudentStatus(studentId, score, attendancePercent)) {
            passCount++;
        } else {
            failCount++;
        }
    }

    // ส่วนแสดงผลสรุป
    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}