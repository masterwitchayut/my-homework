#include <stdio.h>

#define VAT_RATE 0.07

struct Item {
    char name[50];
    float unitPrice;
    int quantity;
};

float calculateSubtotal(int N, struct Item items[]) {
    float sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += items[i].unitPrice * items[i].quantity;
    }
    return sum;
}

void printReceipt(int N, struct Item items[]) {
    float subtotal = calculateSubtotal(N, items);
    float vat = subtotal * VAT_RATE;
    float grandTotal = subtotal + vat;

    printf("--- RECEIPT ---\n");
    for (int i = 0; i < N; i++) {
        printf("%s x %d = %.2f\n", items[i].name, items[i].quantity, items[i].unitPrice * items[i].quantity);
    }
    printf("------------\n");
    printf("Subtotal: %.2f\n", subtotal);
    printf("VAT (7%%): %.2f\n", vat);
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