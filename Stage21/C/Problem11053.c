#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[1001];
    int dp[1001];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}