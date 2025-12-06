#include <stdio.h>

/* ประกาศ Prototype ของฟังก์ชัน */
int GetSet(int data[]);

int main() {
    /* * Fix: "Multiple statements on one line"
     * ต้องประกาศตัวแปรแยกบรรทัดกันอย่างชัดเจน 
     */
    int data[100];
    int num;
    int i;

    /* * Fix: "Stability issues"
     * ใช้ Array data[100] แทน int *data เพื่อให้มีพื้นที่หน่วยความจำแน่นอน
     * (เพราะโจทย์ห้ามใช้ stdlib.h จึง malloc ไม่ได้)
     */
    num = GetSet(data);

    /* แสดงผล N */
    printf("N: %d\n", num);

    /* * Fix: "Deeply nested logic"
     * ใช้การเช็คเงื่อนไขเพื่อจบการทำงานก่อน (Guard Clause) 
     * ทำให้ไม่ต้องมี else ก้อนใหญ่ๆ
     */
    if (num <= 0) {
        return 0;
    }

    /* แสดงผลข้อมูลใน Array */
    for (i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}

/* ฟังก์ชันสำหรับรับค่า */
int GetSet(int data[]) {
    int N;
    int i;

    printf("Enter N (max 100): ");
    
    /* * Fix: "Code structure suggests potential stability issues"
     * ตรวจสอบค่าที่รับมาทันที ถ้า N ไม่ถูกต้อง หรือรับค่าไม่ได้ ให้ return 0
     */
    if (scanf("%d", &N) != 1) {
        return 0;
    }
    
    if (N <= 0) {
        return 0;
    }

    if (N > 100) {
        return 0;
    }

    printf("Enter %d integers:\n", N);
    
    /* วนลูปรับค่าตามจำนวน N */
    for (i = 0; i < N; i++) {
        /* ตรวจสอบว่ารับค่าเป็นตัวเลขได้จริงหรือไม่ */
        if (scanf("%d", &data[i]) != 1) {
            /* ถ้ารับค่าผิดพลาด ให้ตัดจบแค่นั้นแล้วส่งคืนจำนวนเท่าที่รับได้ */
            N = i;
            break;
        }
    }

    return N;
}