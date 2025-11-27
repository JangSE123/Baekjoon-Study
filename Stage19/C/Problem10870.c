#include <stdio.h>

long long memo[100];

long long fibonacci(int n) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int N;
    scanf("%d", &N);

    printf("%lld", fibonacci(N));
    return 0;
}