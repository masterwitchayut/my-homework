#include <stdio.h>

#define VAT_RATE 0.07

struct Item {
    char name[50];
    float unitPrice;
    int quantity;
};

float calculateItemCost(struct Item item) {
    return item.unitPrice * item.quantity;
}

void printReceipt(int N, struct Item items[]) {
    float subTotal = 0.0;
    float totalVAT = 0.0;
    float grandTotal = 0.0;

    printf("--- RECEIPT ---\n");
    for (int i = 0; i < N; i++) {
        float cost = calculateItemCost(items[i]);
        printf("%s x %d = %.2f\n", items[i].name, items[i].quantity, cost);
        subTotal += cost;
    }

    totalVAT = subTotal * VAT_RATE;
    grandTotal = subTotal + totalVAT;

    printf("------------\n");
    printf("Subtotal: %.2f\n", subTotal);
    printf("VAT (7%%): %.2f\n", totalVAT);
    printf("Grand Total: %.2f\n", grandTotal);
}

int main() {
    int N;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Item items[N];

    for (int i = 0; i < N; i++) {
        if (scanf("%s %f %d", items[i].name, &items[i].unitPrice, &items[i].quantity) != 3) {
            return 1;
        }
    }

    printReceipt(N, items);

    return 0;
}