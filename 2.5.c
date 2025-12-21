#include <stdio.h>

int main() {
    int score;
    // CLO 3: แยกบรรทัดเพื่อให้ตรวจสอบและอ่านง่ายขึ้น
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;

    // รับค่าครั้งแรกก่อนเข้า Loop (ตามโครงสร้าง Pre-code)
    if (scanf("%d", &score) != 1) {
        return 1;
    }

    // เงื่อนไข Sentinel คือ -1
    while (score != -1) {
        
        // ตรวจสอบเงื่อนไขการให้เกรด
        if (score >= 80) {
            countA++;
        } 
        else if (score >= 70) {
            countB++;
        } 
        else if (score >= 60) {
            countC++;
        } 
        else if (score >= 50) {
            countD++;
        } 
        else {
            countF++;
        }

        // รับค่าคะแนนถัดไปที่ท้าย Loop (ตามโครงสร้าง Pre-code)
        if (scanf("%d", &score) != 1) {
            break;
        }
    }

    // แสดงผลลัพธ์
    printf("Grade A Count: %d\n", countA);
    printf("Grade B Count: %d\n", countB);
    printf("Grade C Count: %d\n", countC);
    printf("Grade D Count: %d\n", countD);
    printf("Grade F Count: %d\n", countF);

    return 0;
}