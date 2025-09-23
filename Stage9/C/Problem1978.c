#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        if (num <= 1) continue;

        int isPrime = 1;
        for (int j = 2; j * j <= num; j++) {
            if (num % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) count++;
    }
    
    printf("%d\n", count);
    return 0;
}