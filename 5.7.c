#include <stdio.h>

#define SIZE 5

void sort_array_ascending(int array[], int size);
void print_array(int array[], int size);

int main() {
    int numbers[SIZE];
    int original_copy[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
        original_copy[i] = numbers[i];
    }

    sort_array_ascending(numbers, SIZE);

    printf("\n--- ARRAY SORTING REPORT ---\n");
    printf("Original Array: ");
    print_array(original_copy, SIZE);

    printf("Sorted Array (Ascending): ");
    print_array(numbers, SIZE);

    return 0;
}

void sort_array_ascending(int array[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}