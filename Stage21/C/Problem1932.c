#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int dp[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &dp[i][j]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] += dp[i - 1][j];
            else if (j == i) dp[i][j] += dp[i - 1][j - 1];
            else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    int result = 0;
    
    for (int j = 0; j < n; j++) {
        if (dp[n - 1][j] > result) result = dp[n - 1][j];
    }
    
    printf("%d\n", result);
    return 0;
}