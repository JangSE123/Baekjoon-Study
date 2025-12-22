#include <stdio.h>

#define MOD 1000000000LL

int main(void) {
    int N;
    scanf("%d", &N);

    long long dp[101][10] = {0};

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] % MOD;
        dp[i][9] = dp[i - 1][8] % MOD;
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    long long ans = 0;
    for (int j = 0; j <= 9; j++)
        ans = (ans + dp[N][j]) % MOD;

    printf("%lld\n", ans);
    return 0;
}