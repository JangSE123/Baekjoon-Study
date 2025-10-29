#include <stdio.h>
#include <stdbool.h>

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        long long n;
        scanf("%lld", &n);

        while (!isPrime(n)) {
            n++;
        }

        printf("%lld\n", n);
    }

    return 0;
}