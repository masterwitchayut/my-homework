#include <stdio.h>

int main() {
    int score;
    // สร้างตัวแปรไว้นับจำนวนนักเรียนในแต่ละเกรด เริ่มต้นที่ 0
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

    printf("Enter student scores (Enter -1 to stop):\n");

    while (1) {
        printf("Score: ");
        scanf("%d", &score);

        // ตรวจสอบค่า Sentinel (-1) เพื่อออกจาก loop
        if (score == -1) {
            break;
        }

        // ตรวจสอบเงื่อนไขการให้เกรดและเพิ่มจำนวนนับ
        if (score >= 80) {
            countA++;
        } else if (score >= 70) {
            countB++;
        } else if (score >= 60) {
            countC++;
        } else if (score >= 50) {
            countD++;
        } else {
            countF++;
        }
    }

    // แสดงผลลัพธ์สรุปจำนวนนักเรียนในแต่ละเกรด
    printf("\n--- Summary Results ---\n");
    printf("Grade A: %d\n", countA);
    printf("Grade B: %d\n", countB);
    printf("Grade C: %d\n", countC);
    printf("Grade D: %d\n", countD);
    printf("Grade F: %d\n", countF);

    return 0;
}