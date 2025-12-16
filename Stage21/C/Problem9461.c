#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    
    long long dp[101];

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    while (T--) {
        int N;
        scanf("%d", &N);
        printf("%lld\n", dp[N]);
    }

    return 0;
}