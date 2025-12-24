#include <stdio.h>

struct student {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
};

// ฟังก์ชันสำหรับเพิ่ม GPA ตามเงื่อนไขเพศ
struct student upgrade( struct student child ) {
    if (child.sex == 'M') {
        child.gpa = child.gpa * 1.10; // เพิ่ม 10% สำหรับผู้ชาย
    } else if (child.sex == 'F') {
        child.gpa = child.gpa * 1.20; // เพิ่ม 20% สำหรับผู้หญิง
    }
    return child; // คืนค่า struct ที่แก้ไขแล้ว
}

int main() {
    struct student aboy;
    aboy.sex = 'M';
    aboy.gpa = 3.00;

    // เรียกใช้ฟังก์ชันและเก็บค่ากลับมาที่ตัวแปรเดิม
    aboy = upgrade( aboy );

    printf( "%.2f", aboy.gpa ); // ผลลัพธ์จะเป็น 3.30
    return 0;
}