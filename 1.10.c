#include <stdio.h>

/* Named constants */
#define LEVEL_HIGH 3
#define LEVEL_MEDIUM 2
#define ACTIVE 1
#define MIN_AGE 25

int main() {
    int clearanceLevel;
    int age;
    int isActive;
    int accessGranted;

    accessGranted = 0;

    if (scanf("%d %d %d", &clearanceLevel, &age, &isActive) != 3) {
        return 1;
    }

    if (isActive == ACTIVE) {

        if (clearanceLevel == LEVEL_HIGH) {
            accessGranted = 1;
        }
        else if (clearanceLevel == LEVEL_MEDIUM) {

            if (age >= MIN_AGE) {
                accessGranted = 1;
            }
        }
    }

    if (accessGranted == 1) {
        printf("Access Granted\n");
    }
    else {
        printf("Access Denied\n");
    }

    return 0;
}
