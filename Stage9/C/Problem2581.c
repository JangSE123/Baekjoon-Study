#include <stdio.h>

int main(void) {
    int M, N;

    scanf("%d %d", &M, &N);

    int sum = 0, min = 0;

    for (int i = M; i <= N; i++) {
        if (i < 2) continue;

        int prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }

        if (prime) {
            sum += i;
            if (min == 0) min = i;
        }
    }

    if (sum == 0) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", sum, min);
    }

    return 0;
}