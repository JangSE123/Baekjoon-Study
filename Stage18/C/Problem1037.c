#include <stdio.h>

int main() {
    int N, x;
    int min = 2147483647;
    int max = -2147483648;

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &x);
        if (x < min) min = x;
        if (x > max) max = x;
    }

    printf("%lld\n", 1LL * min * max);
    return 0;
}