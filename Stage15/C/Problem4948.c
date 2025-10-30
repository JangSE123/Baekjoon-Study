#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        int count = 0;

        for (int i = n + 1; i <= 2 * n; i++) {
            if (isPrime(i)) count++;
        }
        printf("%d\n", count);
    }

    return 0;
}