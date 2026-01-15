#include <stdio.h>

long long A, B, C;

long long power(long long a, long long b) {
    if (b == 1)
        return a % C;

    long long half = power(a, b / 2);

    if (b % 2 == 0)
        return (half * half) % C;
    else
        return (half * half % C * a) % C;
}

int main(void) {
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld\n", power(A, B));
    return 0;
}