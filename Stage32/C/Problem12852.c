#include <stdio.h>

int dp[1000001];
int prev[1000001];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }

    printf("%d\n", dp[N]);

    int cur = N;
    while (cur != 0) {
        printf("%d ", cur);
        cur = prev[cur];
    }

    return 0;
}