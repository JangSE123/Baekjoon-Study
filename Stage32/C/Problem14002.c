#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int arr[1001];
    int dp[1001];
    int prev[1001];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1;
        prev[i] = -1;
    }

    int maxLen = 0;
    int maxIdx = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }

    int result[1001];
    int idx = 0;
    int cur = maxIdx;

    while (cur != -1) {
        result[idx++] = arr[cur];
        cur = prev[cur];
    }

    printf("%d\n", maxLen);
    for (int i = idx - 1; i >= 0; i--) {
        printf("%d ", result[i]);
    }

    return 0;
}