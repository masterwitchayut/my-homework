#include <stdio.h>

int main() {
    int score;
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

    // รับคะแนนครั้งแรกก่อนเข้า Loop
    if (scanf("%d", &score) != 1) {
        return 1;
    }

    while (score != -1) {
        // ตรวจสอบเงื่อนไขการตัดเกรด
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

        // รับคะแนนคนถัดไปภายใน Loop
        if (scanf("%d", &score) != 1) {
            break;
        }
    }

    // แสดงผลสรุปจำนวนนักเรียนในแต่ละเกรด
    printf("Grade A Count: %d\n", countA);
    printf("Grade B Count: %d\n", countB);
    printf("Grade C Count: %d\n", countC);
    printf("Grade D Count: %d\n", countD);
    printf("Grade F Count: %d\n", countF);

    return 0;
}