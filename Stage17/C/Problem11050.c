#include <stdio.h>

int factorial(int N) {
    int result = 1;
    for (int i = 1; i <= N; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int result = factorial(N) / (factorial(K) * factorial(N - K));
    printf("%d\n", result);

    return 0;
}