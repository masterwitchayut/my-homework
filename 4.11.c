#include <stdio.h>

#define ROWS 2
#define COLS 4

void inputMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter element for Row %d, Col %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int calculateSum(int mat[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += mat[i][j];
        }
    }
    return sum;
}

void displayReport(int mat[ROWS][COLS], int total) {
    printf("\n--- 2D ARRAY SUMMATION REPORT ---\n");
    printf("Recorded Matrix (2x4):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nTotal Sum of all elements: %d\n", total);
}

int main() {
    int matrix[ROWS][COLS];
    int total_sum = 0;

    printf("Enter %d integer numbers for the 2x4 matrix:\n", ROWS * COLS);
    
    inputMatrix(matrix);
    total_sum = calculateSum(matrix);
    displayReport(matrix, total_sum);

    return 0;
}