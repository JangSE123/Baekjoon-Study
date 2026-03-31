#include <stdio.h>

int M, N;
int map[501][501];
int dp[501][501];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) return 1;

    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if (map[nx][ny] < map[x][y]) {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }

    return dp[x][y];
}

int main(void) {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }

    printf("%d\n", dfs(0, 0));
    return 0;
}