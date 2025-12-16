#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    
    if (N == 1) {
        printf("1");
        return 0;
    }

    int dp[N + 1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    printf("%d", dp[N]);
    return 0;
}