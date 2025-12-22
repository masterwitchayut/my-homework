#include <stdio.h>

void calculate_time(int total_seconds, int *h, int *m, int *s);

int main() {
    int total_seconds;
    int hours, minutes, seconds;

    scanf("%d", &total_seconds);

    calculate_time(total_seconds, &hours, &minutes, &seconds);

    printf("\n--- TIME CONVERSION REPORT ---\n");
    printf("Total Seconds: %d s\n", total_seconds);
    printf("Converted Time: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}

void calculate_time(int total_seconds, int *h, int *m, int *s) {
    *h = total_seconds / 3600;
    *m = (total_seconds % 3600) / 60;
    *s = total_seconds % 60;
}