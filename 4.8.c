#include <stdio.h>

struct Campaign {
    char name[50];
    float productPrice;
    int salesCount;
    float adSpend;
};

float getCommissionRate(int salesCount) {
    if (salesCount >= 20) {
        return 0.20;
    } else if (salesCount >= 10) {
        return 0.15;
    } else {
        return 0.10;
    }
}

void printCampaign(struct Campaign c) {
    float rate = getCommissionRate(c.salesCount);
    float totalRevenue = c.salesCount * c.productPrice;
    float totalCommission = totalRevenue * rate;
    float netProfitLoss = totalCommission - c.adSpend;

    printf("--- Campaign: %s ---\n", c.name);
    printf("Sales: %d, Ad Spend: %.2f\n", c.salesCount, c.adSpend);
    printf("Rate Used: %.0f%%\n", rate * 100);
    printf("Calculation: (%.2f * %.0f%%) - %.2f = %.2f\n", 
            totalRevenue, rate * 100, c.adSpend, netProfitLoss);
    printf("Net Result: %.2f\n", netProfitLoss);
}

int main() {
    int N, i;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Campaign campaigns[N];

    for (i = 0; i < N; i++) {
        if (scanf("%s %f %d %f", campaigns[i].name, &campaigns[i].productPrice, 
                  &campaigns[i].salesCount, &campaigns[i].adSpend) != 4) {
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        printCampaign(campaigns[i]);
    }

    return 0;
}