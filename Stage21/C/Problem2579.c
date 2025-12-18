#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    int score[301];
    int dp[301];

    for (int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
    }

    if (n == 1) {
        printf("%d\n", score[1]);
        return 0;
    }
    
    if (n == 2) {
        printf("%d\n", score[1] + score[2]);
        return 0;
    }

    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }

    printf("%d\n", dp[n]);
    
    return 0;
}