#include <stdio.h>

void checkResult(int studentId, int score, float attendancePercent,
                 int *passCount, int *failCount)
{

    printf("Student ID %d: ", studentId);

    if (score >= 50 && attendancePercent >= 75)
    {
        printf("PASS\n");
        (*passCount)++;
    }
    else
    {
        printf("FAIL (");

        if (score < 50 && attendancePercent < 75)
        {
            printf("Both Score and Attendance");
        }
        else if (score < 50)
        {
            printf("Score");
        }
        else
        {
            printf("Attendance");
        }

        printf(")\n");
        (*failCount)++;
    }
}

int main()
{
    int N, i;
    int studentId, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0;
    int failCount = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d %d",
              &studentId, &score, &totalClasses, &absentClasses);

        attendancePercent =
            (float)(totalClasses - absentClasses) / totalClasses * 100.0;

        checkResult(studentId, score, attendancePercent,
                    &passCount, &failCount);
    }

    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}
