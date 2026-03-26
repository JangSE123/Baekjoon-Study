#include <stdio.h>
#include <limits.h>

#define MAX 501

long long arr[MAX];
long long sum[MAX];
long long dp[MAX][MAX];

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int K;
        scanf("%d", &K);

        for (int i = 1; i <= K; i++) {
            scanf("%lld", &arr[i]);
            sum[i] = 0;
            
            for (int j = 1; j <= K; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= K; i++) {
            sum[i] = sum[i - 1] + arr[i];
        }

        for (int len = 2; len <= K; len++) {
            for (int i = 1; i <= K - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = LLONG_MAX;

                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k + 1][j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }

                dp[i][j] += sum[j] - sum[i - 1];
            }
        }

        printf("%lld\n", dp[1][K]);
    }

    return 0;
}