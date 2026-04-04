#include <stdio.h>

int cards[1000];
int dp[1000][1000];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int sum = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &cards[i]);
            sum += cards[i];
        }

        for (int i = 0; i < N; i++) {
            dp[i][i] = cards[i];
        }

        for (int len = 2; len <= N; len++) {
            for (int l = 0; l + len - 1 < N; l++) {
                int r = l + len - 1;

                dp[l][r] = max(cards[l] - dp[l + 1][r], cards[r] - dp[l][r - 1]);    
            }
        }

        int result = (sum + dp[0][N - 1]) / 2;
        printf("%d\n", result);
    }
}