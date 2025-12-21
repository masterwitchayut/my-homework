#include <stdio.h>

#define SHIPPING_FEE 50.0

struct Order {
    int itemId;
    float unitPrice;
    int quantity;
};

int main() {
    int N, i;
    float grandTotal = 0.0;

    // รับจำนวนรายการสั่งซื้อ
    scanf("%d", &N);

    struct Order orders[N];

    // รับข้อมูลแต่ละรายการ
    for (i = 0; i < N; i++) {
        float itemTotal;

        scanf("%d %f %d",
              &orders[i].itemId,
              &orders[i].unitPrice,
              &orders[i].quantity);

        // คำนวณราคารวมต่อรายการ + ค่าจัดส่ง
        itemTotal = (orders[i].unitPrice * orders[i].quantity) + SHIPPING_FEE;

        // ลดราคา 10% ถ้าเกิน 500
        if (itemTotal > 500.0) {
            itemTotal *= 0.90;
        }

        // รวมยอดทั้งหมด
        grandTotal += itemTotal;
    }

    // แสดงผลรวมทั้งหมด
    printf("Grand Total: %.2f\n", grandTotal);

    return 0;
}
