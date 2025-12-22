#include <stdio.h>

void calculate_geometry(float side, float *area, float *volume);

int main() {
    float side_length, area_result, volume_result;

    scanf("%f", &side_length);

    calculate_geometry(side_length, &area_result, &volume_result);

    printf("\n--- CUBE GEOMETRY REPORT ---\n");
    printf("Side Length: %.2f\n", side_length);
    printf("Surface Area: %.2f\n", area_result);
    printf("Volume: %.2f\n", volume_result);

    return 0;
}

void calculate_geometry(float side, float *area, float *volume) {
    *area = 6 * (side * side);
    *volume = side * side * side;
}