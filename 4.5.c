#include <stdio.h>

#define SHIPPING_FEE 50.0

struct Order {
    int itemId;
    float unitPrice;
    int quantity;
};

float calculateTotal(struct Order order) {
    float itemTotal = (order.unitPrice * order.quantity) + SHIPPING_FEE;
    if (itemTotal >= 500.0) {
        itemTotal *= 0.90;
    }
    return itemTotal;
}

int main() {
    int N, i;
    float grandTotal = 0.0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Order orders[N];

    for (i = 0; i < N; i++) {
        if (scanf("%d %f %d", &orders[i].itemId, &orders[i].unitPrice, &orders[i].quantity) != 3) {
            return 1;
        }
        grandTotal += calculateTotal(orders[i]);
    }

    printf("Grand Total: %.2f\n", grandTotal);

    return 0;
}