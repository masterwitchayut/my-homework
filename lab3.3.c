#include <stdio.h>

struct student {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
};

// ฟังก์ชันรับค่า struct เข้าไป และ return struct ที่แก้ไขแล้วกลับออกมา
struct student upgrade( struct student child ) {
    if (child.sex == 'M') {
        child.gpa = child.gpa * 1.10; // เพิ่ม 10%
    } else if (child.sex == 'F') {
        child.gpa = child.gpa * 1.20; // เพิ่ม 20%
    }
    return child; // ส่ง struct ที่แก้ไขแล้วกลับไป
}

int main() {
    struct student aboy;
    aboy.sex = 'M';
    aboy.gpa = 3.00;

    // เรียกใช้ฟังก์ชันโดยนำค่าที่ return มาเก็บไว้ในตัวแปรเดิม
    aboy = upgrade( aboy );

    printf( "%.2f", aboy.gpa );

    return 0;
}