#include <stdio.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int main(void) {
    int N;
    scanf("%d", &N);

    int dp[N][3];

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
    }

    for (int i = 1; i < N; i++) {
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    printf("%d", min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2])));
    return 0;
}