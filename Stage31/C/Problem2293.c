#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int coins[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    int dp[10001] = {0};
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int coin = coins[i];
        for (int j = coin; j <= k; j++) {
            dp[j] += dp[j - coin];
        }
    }

    printf("%d\n", dp[k]);
    return 0;
}