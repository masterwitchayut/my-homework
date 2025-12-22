#include <stdio.h>

void calculate_stats(int scores[], int size, int *sum, float *avg);

int main() {
    int student_scores[5];
    int total_sum;
    float average;
    int i;

    for (i = 0; i < 5; i++) {
        scanf("%d", &student_scores[i]);
    }

    calculate_stats(student_scores, 5, &total_sum, &average);

    printf("\n--- SCORE STATISTICS REPORT ---\n");
    printf("Scores: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", student_scores[i]);
    }
    
    printf("\nTotal Sum: %d\n", total_sum);
    printf("Average: %.2f\n", average);

    return 0;
}

void calculate_stats(int scores[], int size, int *sum, float *avg) {
    *sum = 0;
    for (int i = 0; i < size; i++) {
        *sum += scores[i];
    }
    *avg = (float)*sum / size;
}