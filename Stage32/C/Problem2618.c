#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001

int N, W;
int event[MAX][2];
int dp[MAX][MAX];
int path[MAX][MAX];

int abs_val(int x) {
    return x < 0 ? -x : x;
}

int dist(int from, int to, int type) {
    int x1, y1;

    if (from == 0) {
        if (type == 1) {
            x1 = 1; y1 = 1;
        } else {
            x1 = N; y1 = N;
        }
    } else {
        x1 = event[from][0];
        y1 = event[from][1];
    }

    int x2 = event[to][0];
    int y2 = event[to][1];

    return abs_val(x1 - x2) + abs_val(y1 - y2);
}

int solve(int a, int b) {
    if (a == W || b == W) return 0;

    if (dp[a][b] != -1) return dp[a][b];

    int next = (a > b ? a : b) + 1;

    int case1 = solve(next, b) + dist(a, next, 1);
    int case2 = solve(a, next) + dist(b, next, 2);

    if (case1 < case2) {
        path[a][b] = 1;
        return dp[a][b] = case1;
    } else {
        path[a][b] = 2;
        return dp[a][b] = case2;
    }
}

void trace(int a, int b) {
    if (a == W || b == W) return;

    int next = (a > b ? a : b) + 1;

    if (path[a][b] == 1) {
        printf("1\n");
        trace(next, b);
    } else {
        printf("2\n");
        trace(a, next);
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &W);

    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= W; i++) {
        scanf("%d %d", &event[i][0], &event[i][1]);
    }

    printf("%d\n", solve(0, 0));
    trace(0, 0);

    return 0;
}