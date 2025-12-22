#include <stdio.h>

void calculate_rectangle(float width, float height, float *area, float *perimeter);

int main() {
    float width, height, area, perimeter;

    scanf("%f", &width);
    scanf("%f", &height);

    calculate_rectangle(width, height, &area, &perimeter);

    printf("\n--- RECTANGLE CALCULATION REPORT ---\n");
    printf("Width: %.2f, Height: %.2f\n", width, height);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);

    return 0;
}

void calculate_rectangle(float width, float height, float *area, float *perimeter) {
    *area = width * height;
    *perimeter = 2 * (width + height);
}