#include <stdio.h>
#include <limits.h>

int arr[501][2];
int dp[501][501];

int min(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    for (int len = 1; len < N; len++) {
        for (int i = 0; i + len < N; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + arr[i][0] * arr[k][1] * arr[j][1];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    printf("%d\n", dp[0][N - 1]);
    return 0;
}