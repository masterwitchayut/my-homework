#include <stdio.h>

/* Named constants */
#define TYPE_RESIDENTIAL 1
#define TYPE_BUSINESS 2

#define RES_LIMIT 100
#define BUS_LIMIT 500

#define RES_RATE_LOW 3.0
#define RES_RATE_HIGH 4.0

#define BUS_RATE_LOW 5.0
#define BUS_RATE_HIGH 6.5

int main() {
    int customerType;
    float consumption_kWh;
    float totalBill = 0.0;

    /* Input */
    if (scanf("%d %f", &customerType, &consumption_kWh) != 2) {
        return 1;
    }

    /* Customer type checking */
    if (customerType == TYPE_RESIDENTIAL) {

        if (consumption_kWh <= RES_LIMIT) {
            totalBill = consumption_kWh * RES_RATE_LOW;
        } else {
            totalBill = consumption_kWh * RES_RATE_HIGH;
        }

        printf("%.2f\n", totalBill);

    } else if (customerType == TYPE_BUSINESS) {

        if (consumption_kWh <= BUS_LIMIT) {
            totalBill = consumption_kWh * BUS_RATE_LOW;
        } else {
            totalBill = consumption_kWh * BUS_RATE_HIGH;
        }

        printf("%.2f\n", totalBill);

    } else {
        printf("Invalid Customer Type\n");
    }

    return 0;
}
