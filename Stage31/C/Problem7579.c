#include <stdio.h>

int memory[101];
int cost[101];
int dp[10001];

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &memory[i]);
    }

    int maxCost = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &cost[i]);
        maxCost += cost[i];
    }

    for (int i = 0; i < N; i++) {
        for (int c = maxCost; c >= cost[i]; c--) {
            if (dp[c] < dp[c - cost[i]] + memory[i]) {
                dp[c] = dp[c - cost[i]] + memory[i];
            }
        }
    }

    for (int c = 0; c <= maxCost; c++) {
        if (dp[c] >= M) {
            printf("%d\n", c);
            break;
        }
    }

    return 0;
}