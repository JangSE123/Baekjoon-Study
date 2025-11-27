#include <stdio.h>

long long factorial(long long n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    long long N;
    scanf("%lld", &N);

    printf("%lld", factorial(N));
    return 0;
}