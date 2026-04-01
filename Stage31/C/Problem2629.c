#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int weights[30];
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    int dp[15001] = {0};
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        int next[15001] = {0};

        for (int j = 0; j <= 15000; j++) {
            if (!dp[j]) continue;

            next[j] = 1;

            if (j + weights[i] <= 15000)
                next[j + weights[i]] = 1;

            int diff = abs(j - weights[i]);
            next[diff] = 1;
        }

        for (int j = 0; j <= 15000; j++) {
            dp[j] = next[j];
        }
    }

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int bead;
        scanf("%d", &bead);

        if (bead > 15000) printf("N ");
        else if (dp[bead]) printf("Y ");
        else printf("N ");
    }

    return 0;
}