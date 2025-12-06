#include <stdio.h>

// CLO3 Fix: กำหนดค่าคงที่ที่มีชื่อ (Named Constant) สำหรับขนาดสูงสุดของเมทริกซ์
#define MAX_SIZE 100

// ฟังก์ชัน GetMatrix: รับค่าองค์ประกอบของเมทริกซ์และขนาด (rows, cols)
// matrixData: รับอาร์เรย์แบบหนึ่งมิติเพื่อจัดเก็บข้อมูลเมทริกซ์ (ใช้จำลองเมทริกซ์ 2D)
// Rows, Cols: ตัวชี้ไปยังตัวแปรใน main() เพื่ออัปเดตขนาดเมทริกซ์
void GetMatrix(int matrixData[], int *Rows, int *Cols)
{
    int rows, cols;
    int i, j; // ตัวแปรวนซ้ำ (loop iterators)

    printf("Enter rows (m): ");
    scanf("%d", Rows);

    // อ่านค่า rows จากตัวชี้ *Rows มาเก็บไว้ในตัวแปรท้องถิ่น rows
    rows = *Rows;

    printf("Enter cols (n): ");
    scanf("%d", Cols);

    // อ่านค่า cols จากตัวชี้ *Cols มาเก็บไว้ในตัวแปรท้องถิ่น cols
    cols = *Cols;

    // CLO3 Fix: ใช้ค่าคงที่ MAX_SIZE แทนตัวเลขวิเศษ 100
    // เหตุผล: ป้องกันไม่ให้ผู้ใช้อาร์เรย์เกินขนาด MAX_SIZE ที่ประกาศไว้ใน main() และป้องกันขนาดที่ผิดปกติ
    if (rows <= 0 || cols <= 0 || (rows * cols) > MAX_SIZE)
    {
        printf("Error: Matrix size out of bounds (Max %d elements).\n", MAX_SIZE);
        *Rows = 0;
        *Cols = 0;
        return;
    }

    printf("Enter elements (%d x %d):\n", rows, cols);

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);

            // การเข้าถึงอาร์เรย์แบบ 2D โดยใช้ 1D: matrixData[row * cols + col]
            scanf("%d", &matrixData[(i * cols) + j]);
        }
    }
}

int main()
{
    // CLO3 Fix: ใช้ค่าคงที่ MAX_SIZE แทนตัวเลขวิเศษ 100
    int matrixData[MAX_SIZE];
    int rows, cols;
    int i, j;
    
    // CLO1 Comment: โครงสร้างนี้ใช้ Static Array และ Pointer Parameter ซึ่งเป็นโครงสร้างมาตรฐานของ C 
    // และยังคงรักษาฟังก์ชัน GetMatrix ตามที่กำหนดไว้
    GetMatrix(matrixData, &rows, &cols);

    if (rows <= 0 || cols <= 0)
    {
        return 0;
    }

    printf("\n--- Result Matrix ---\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            // พิมพ์ค่าเมทริกซ์ที่เก็บในอาร์เรย์ 1D
            printf("%4d", matrixData[(i * cols) + j]);
        }
        printf("\n");
    }

    return 0;
}