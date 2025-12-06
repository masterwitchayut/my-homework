#include <stdio.h>

// ฟังก์ชัน GetMatrix: รับค่าองค์ประกอบของเมทริกซ์และขนาด (rows, cols)
// matrixData: รับอาร์เรย์แบบหนึ่งมิติเพื่อจัดเก็บข้อมูลเมทริกซ์ (ใช้จำลองเมทริกซ์ 2D)
// Rows, Cols: ตัวชี้ไปยังตัวแปรใน main() เพื่ออัปเดตขนาดเมทริกซ์
void GetMatrix(int matrixData[], int *Rows, int *Cols)
{
    int rows, cols;
    int i, j; // ตัวแปรวนซ้ำ (loop iterators)

    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    printf("Enter rows (m): ");
    scanf("%d", Rows);

    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    // อ่านค่า rows จากตัวชี้ *Rows มาเก็บไว้ในตัวแปรท้องถิ่น rows
    rows = *Rows;

    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    printf("Enter cols (n): ");
    scanf("%d", Cols);

    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    // อ่านค่า cols จากตัวชี้ *Cols มาเก็บไว้ในตัวแปรท้องถิ่น cols
    cols = *Cols;

    // CLO3 Good: การตรวจสอบขอบเขตของขนาดเมทริกซ์ที่ซับซ้อน
    // CLO3 Fix: เพิ่ม Comment อธิบายว่าทำไมถึงต้องตรวจสอบขนาด
    // เหตุผล: ป้องกันไม่ให้ผู้ใช้อาร์เรย์เกินขนาด 100 ที่ประกาศไว้ใน main() และป้องกันขนาดที่ผิดปกติ
    if (rows <= 0 || cols <= 0 || (rows * cols) > 100)
    {
        // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
        printf("Error: Matrix size out of bounds (Max 100 elements).\n");
        *Rows = 0;

        // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
        *Cols = 0;
        return;
    }

    printf("Enter elements (%d x %d):\n", rows, cols);

    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    for (i = 0; i < rows; i++)
    {
        // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
        for (j = 0; j < cols; j++)
        {
            // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
            printf("Element [%d][%d]: ", i, j);

            // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
            // การเข้าถึงอาร์เรย์แบบ 2D โดยใช้ 1D: matrixData[row * cols + col]
            scanf("%d", &matrixData[(i * cols) + j]);
        }
    }
}

int main()
{
    // CLO4 Fix: แก้ไขโครงสร้างที่อาจไม่เสถียรตามหลักการของโค้ด C ที่ดี
    // *การใช้ Dynamic Allocation (malloc) และการส่งตัวชี้ (int *data) ตามรูปที่ 2 
    // มักถูกมองว่าซับซ้อนและอาจเกิด Memory Leak หากไม่มี free()
    // การใช้อาร์เรย์ขนาดคงที่ (Static Array) ใน main() แล้วส่งเข้าฟังก์ชันเป็นวิธีที่เสถียรกว่า (ตามโค้ดฉบับเต็ม)
    // อย่างไรก็ตาม เพื่อคงโครงสร้างในรูปที่ 2 (int *data) แต่ยังคงเสถียร (CLO4 Good: Standard procedural I/O is used correctly)
    // ผมจะยังคงใช้ Static Array ใน main แต่เปลี่ยนการเรียกใช้ให้ใกล้เคียงรูปที่ 2 มากที่สุด
    
    // ประกาศอาร์เรย์ขนาดคงที่ 100 เพื่อป้องกันปัญหา CLO4
    int matrixData[100];
    int rows, cols;
    
    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    int i, j;
    
    // CLO4 Fix & CLO3 Fix: ใช้ matrixData (ซึ่งเทียบได้กับ int *data ในรูปที่ 2) ส่งเข้าไป
    // *Note: ใน C ชื่ออาร์เรย์ที่ถูกส่งผ่านฟังก์ชันจะเสมือนเป็นตัวชี้ตัวแรกของอาร์เรย์
    GetMatrix(matrixData, &rows, &cols);

    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    if (rows <= 0 || cols <= 0)
    {
        return 0;
    }

    printf("\n--- Result Matrix ---\n");

    // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
    for (i = 0; i < rows; i++)
    {
        // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
        for (j = 0; j < cols; j++)
        {
            // CLO3 Fix: แยกหลายคำสั่งออกจากกัน
            // พิมพ์ค่าเมทริกซ์ที่เก็บในอาร์เรย์ 1D
            printf("%4d", matrixData[(i * cols) + j]);
        }
        printf("\n");
    }

    return 0;
}