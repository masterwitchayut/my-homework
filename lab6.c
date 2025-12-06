#include <stdio.h>

// GetMatrix: ฟังก์ชันสำหรับรับค่าขนาดและองค์ประกอบของเมทริกซ์
int GetMatrix(int *rows_ptr, int *cols_ptr) 
{
    // CLO3 Fix: เปลี่ยนชื่อตัวแปร i เป็น row_index
    int row_index;
    // CLO3 Fix: เปลี่ยนชื่อตัวแปร n เป็น col_index
    int col_index; 
    
    // ใช้ "ตัวเลขวิเศษ" 20 ในการประกาศขนาดอาร์เรย์
    int matrix_data[20][20]; 

    printf("Enter row: ");
    // CLO3 Fix: ใช้ตัวชี้ rows_ptr แทน row
    scanf("%d", rows_ptr);

    printf("Enter col: ");
    // CLO3 Fix: ใช้ตัวชี้ cols_ptr แทน col
    scanf("%d", cols_ptr);

    // ใช้ *rows_ptr และ *cols_ptr ในการตรวจสอบเงื่อนไข
    if (*rows_ptr <= 0 || *cols_ptr <= 0 || *rows_ptr > 20 || *cols_ptr > 20)
    {
        printf("Error: Matrix size out of bounds (Max 20x20).\n");
        *rows_ptr = 0;
        *cols_ptr = 0;
        return 0;
    }

    printf("Input matrix:\n");
    // ใช้ *rows_ptr ในเงื่อนไข loop
    for(row_index = 0; row_index < *rows_ptr; row_index++) 
    {
        // ใช้ *cols_ptr ในเงื่อนไข loop
        for(col_index = 0; col_index < *cols_ptr; col_index++) 
        {
            printf("a[%d][%d] = ", row_index, col_index);
            // ใช้ตัวชี้ rows_ptr, cols_ptr
            scanf("%d", &matrix_data[row_index][col_index]);
        }
    }

    printf("\nMatrix:\n");
    for(row_index = 0; row_index < *rows_ptr; row_index++) 
    {
        for(col_index = 0; col_index < *cols_ptr; col_index++) 
        {
            printf("%d ", matrix_data[row_index][col_index]);
        }
        printf("\n");
    }

    return 0;
}

int main() 
{
    // CLO3 Fix: เปลี่ยนชื่อตัวแปร m เป็น rows
    int rows;
    // CLO3 Fix: เปลี่ยนชื่อตัวแปร n เป็น cols
    int cols;
    
    // ส่งที่อยู่ของ rows และ cols ไปยัง GetMatrix
    GetMatrix(&rows, &cols);
    
    return 0;
}