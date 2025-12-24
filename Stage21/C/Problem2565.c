#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Wire;

int compare(const void* x, const void* y) {
    Wire* w1 = (Wire*)x;
    Wire* w2 = (Wire*)y;
    return w1 -> a - w2 -> a;
}

int main(void) {
    int n;
    scanf("%d", &n);

    Wire wire[101];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wire[i].a, &wire[i].b);
    }

    qsort(wire, n, sizeof(Wire), compare);

    int dp[101];
    for (int i = 0; i < n; i++) dp[i] = 1;

    int lis = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (wire[j].b < wire[i].b) {
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        if (lis < dp[i]) lis = dp[i];
    }

    printf("%d\n", n - lis);
    return 0;
}