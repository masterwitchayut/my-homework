#include <stdio.h>

int main() {
 
    int n;
 
    int i;

    printf("ต้องการให้แสดง 'Hello World' กี่บรรทัด? (ป้อนตัวเลข n): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Hello World\n");
    }

    return 0;
}