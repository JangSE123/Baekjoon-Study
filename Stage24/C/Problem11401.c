#include <stdio.h>

#define MOD 1000000007LL

long long fact[4000001];

long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return result;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    long long numerator = fact[N];
    long long denominator = fact[K] * fact[N - K] % MOD;

    long long answer = numerator * modPow(denominator, MOD - 2) % MOD;
    printf("%lld\n", answer);

    return 0;
}