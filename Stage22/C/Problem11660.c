#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    static int sum[1025][1025];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            scanf("%d", &x);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
        }
    }

    while (M--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int ans = sum[x2][y2]
                - sum[x1 - 1][y2]
                - sum[x2][y1 - 1]
                + sum[x1 - 1][y1 - 1];

        printf("%d\n", ans);
    }

    return 0;
}