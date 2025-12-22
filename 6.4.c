#include <stdio.h>

void find_circle_properties(float radius, float *area, float *circumference);

int main() {
    float radius, area, circumference;

    scanf("%f", &radius);

    find_circle_properties(radius, &area, &circumference);

    printf("\n--- CIRCLE PROPERTY REPORT ---\n");
    printf("Radius: %.2f\n", radius);
    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);

    return 0;
}

void find_circle_properties(float radius, float *area, float *circumference) {
    const float PI = 3.14159;
    *area = PI * radius * radius;
    *circumference = 2 * PI * radius;
}