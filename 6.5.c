#include <stdio.h>

void convert_temperature(float celsius, float *fahrenheit, float *kelvin);

int main() {
    float celsius, fahrenheit, kelvin;

    scanf("%f", &celsius);

    convert_temperature(celsius, &fahrenheit, &kelvin);

    printf("\n--- TEMPERATURE CONVERSION REPORT ---\n");
    printf("Celsius: %.2f C\n", celsius);
    printf("Fahrenheit: %.2f F\n", fahrenheit);
    printf("Kelvin: %.2f K\n", kelvin);

    return 0;
}

void convert_temperature(float celsius, float *fahrenheit, float *kelvin) {
    *fahrenheit = (celsius * 9 / 5) + 32;
    *kelvin = celsius + 273.15;
}