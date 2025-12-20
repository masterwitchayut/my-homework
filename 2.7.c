#include <stdio.h>

int main() {
    int N, i;
    int countFizzBuzz = 0;
    int countFizz = 0;
    int countBuzz = 0;
    int countOther = 0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    // วนลูปตั้งแต่ 1 ถึง N (inclusive)
    for (i = 1; i <= N; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            // หารด้วย 3 และ 5 ลงตัว (หาร 15 ลงตัว)
            countFizzBuzz++;
        } else if (i % 3 == 0) {
            // หารด้วย 3 ลงตัวเท่านั้น
            countFizz++;
        } else if (i % 5 == 0) {
            // หารด้วย 5 ลงตัวเท่านั้น
            countBuzz++;
        } else {
            // ไม่เข้าเงื่อนไขใดๆ เลย
            countOther++;
        }
    }

    printf("Count FizzBuzz (by 15): %d\n", countFizzBuzz);
    printf("Count Fizz (by 3 only): %d\n", countFizz);
    printf("Count Buzz (by 5 only): %d\n", countBuzz);
    printf("Count Other: %d\n", countOther);

    return 0;
}