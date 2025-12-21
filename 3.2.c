#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N, i;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Student students[N];

    for (i = 0; i < N; i++) {
        if (scanf("%d %f %s",
                  &students[i].studentId,
                  &students[i].score,
                  students[i].name) != 3) {
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        printf("Student ID: %d\n", students[i].studentId);
        printf("Score: %.2f\n", students[i].score);
        printf("Name: %s\n", students[i].name);
    }

    return 0;
}
