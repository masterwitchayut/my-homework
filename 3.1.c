#include <stdio.h>

struct Product {
    char name[50];
    int productId;
    float price;
};

int main() {
    struct Product item;

    if (scanf("%d %f %s", &item.productId, &item.price, item.name) != 3) {
        return 1;
    }

    printf("Product ID: %d\n", item.productId);
    printf("Price: %.2f\n", item.price);
    printf("Name: %s\n", item.name);

    return 0;
}
