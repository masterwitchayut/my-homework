#include <stdio.h>

// 1. ประกาศโครงสร้าง (struct) ชื่อ Campaign
struct Campaign {
    char name[50];
    float productPrice;
    int salesCount;
    float adSpend;
};

int main() {
    int N, i;

    // 2. รับค่า N (จำนวนแคมเปญ)
    printf("Enter number of campaigns: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;
    }

    // ประกาศ array ของ struct ตามจำนวน N
    struct Campaign campaigns[N];

    // 3. ใช้ for loop เพื่อรับข้อมูล N แคมเปญ
    for (i = 0; i < N; i++) {
        printf("\nCampaign #%d (Name Price Sales AdSpend): ", i + 1);
        if (scanf("%s %f %d %f", 
                  campaigns[i].name, 
                  &campaigns[i].productPrice, 
                  &campaigns[i].salesCount, 
                  &campaigns[i].adSpend) != 4) {
            return 1;
        }

        float commissionRate = 0.0;
        float totalRevenue;
        float totalCommission;
        float netProfitLoss;

        // 4. ภายในลูป: กำหนดอัตราคอมมิชชันตามเงื่อนไข
        if (campaigns[i].salesCount >= 20) {
            commissionRate = 0.20; // 20%
        } else if (campaigns[i].salesCount >= 10) {
            commissionRate = 0.15; // 15%
        } else {
            commissionRate = 0.10; // 10%
        }

        // คำนวณตามสูตร
        totalRevenue = campaigns[i].salesCount * campaigns[i].productPrice;
        totalCommission = totalRevenue * commissionRate;
        netProfitLoss = totalCommission - campaigns[i].adSpend;

        // 5. แสดงผลลัพธ์ของแต่ละแคมเปญ
        printf("--- Campaign: %s ---\n", campaigns[i].name);
        printf("Sales: %d, Ad Spend: %.2f\n", campaigns[i].salesCount, campaigns[i].adSpend);
        printf("Rate Used: %.0f%%\n", commissionRate * 100);
        printf("Calculation: (%.2f * %.0f%%) - %.2f = %.2f\n", 
               totalRevenue, commissionRate * 100, campaigns[i].adSpend, netProfitLoss);
        printf("Net Result: %.2f\n", netProfitLoss);
    }

    return 0;
}