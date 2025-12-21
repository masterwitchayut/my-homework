#include <stdio.h>

int grade(int score);

int main() { //
    int score; 
    if (scanf("%d", &score) != 1) {
        return 1;
    }
    grade(score);
    return 0;
}

int grade(int score) {

    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0; //
    
    while (score != -1) { //

        if (score >= 80) //
        {

            countA++;
        }
        else if (score >= 70)
        {
            countB++;
        }
        else if (score >= 60)
        {
            countC++;
        }
            
        else if (score >= 50)
        {
            countD++;
        }
        else if (score < 50)
        {
            countF++;
        }

        if (scanf("%d", &score) != 1) { //
            break;
        }
    }
    printf("Grade A Count: %d\n", countA); //
    printf("Grade B Count: %d\n", countB); //
    printf("Grade C Count: %d\n", countC); //
    printf("Grade D Count: %d\n", countD); //
    printf("Grade F Count: %d\n", countF); //
    return 0;
}