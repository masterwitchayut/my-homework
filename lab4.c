#include <stdio.h>

/* ประกาศ Prototype ของฟังก์ชัน */
int GetSet(int data[]);

int main() {
    /* Fix: แยกบรรทัดการประกาศตัวแปรเพื่อความอ่านง่าย */
    int data[100];
    int num;

    /* เรียกใช้ฟังก์ชันรับค่า */
    num = GetSet(data);

    printf("N: %d\n", num);

    /* * Fix: ลดความซ้อนของโค้ด (Nesting) 
     * ถ้าไม่มีข้อมูล (num <= 0) ให้จบการทำงานทันที ไม่ต้องมี else ครอบส่วนที่เหลือ
     */
    if (num <= 0) {
        return 0;
    }

    /* แสดงผลข้อมูลใน Array */
    for (int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}

int GetSet(int data[]) {
    int N;

    printf("Enter N (max 100): ");
    
    /* * Fix: เพิ่มคอมเมนต์อธิบาย Logic การตรวจสอบ Input (Validation)
     * ตรวจสอบว่ารับค่าได้จริง และค่าต้องอยู่ระหว่าง 1 ถึง 100 
     */
    if (scanf("%d", &N) != 1 || N <= 0 || N > 100) {
        // คืนค่า 0 ทันทีหากข้อมูลไม่ถูกต้อง เพื่อป้องกันการทำงานต่อที่ผิดพลาด
        return 0; 
    }

    printf("Enter %d integers:\n", N);
    
    /* วนลูปรับค่าตามจำนวน N */
    for (int i = 0; i < N; i++) {
        /* * ตรวจสอบการรับค่าตัวเลขแต่ละตัว 
         * หากรับค่าไม่ได้ (เช่น ผู้ใช้พิมพ์ตัวอักษร) ให้หยุดรับค่าทันที
         */
        if (scanf("%d", &data[i]) != 1) {
            // ปรับค่า N ให้เท่ากับจำนวนที่รับได้จริง แล้วออกจากลูป
            N = i; 
            break; 
        }
    }

    return N;
}