#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int dp[100001] = {0};

    for (int i = 0; i < N; i++) {
        int W, V;
        scanf("%d %d", &W, &V);

        for (int w = K; w >= W; w--) {
            dp[w] = max(dp[w], dp[w - W] + V);
        }
    }

    printf("%d\n", dp[K]);
    return 0;
}