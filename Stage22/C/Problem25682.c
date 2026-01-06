#include <stdio.h>

int N, M, K;
char board[2001][2001];
int psumW[2001][2001];
int psumB[2001][2001];

int min(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= N; i++) {
        scanf("%s", board[i] + 1);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int isWhite = ((i + j) % 2 == 0);

            int w = (board[i][j] == (isWhite ? 'W' : 'B')) ? 0 : 1;
            int b = (board[i][j] == (isWhite ? 'B' : 'W')) ? 0 : 1;

            psumW[i][j] = psumW[i - 1][j] + psumW[i][j - 1]
                        - psumW[i - 1][j - 1] + w;

            psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1]
                        - psumB[i - 1][j - 1] + b;
        }
    }

    int ans = 1e9;

    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            int w = psumW[i][j] - psumW[i - K][j]
                  - psumW[i][j - K] + psumW[i - K][j - K];

            int b = psumB[i][j] - psumB[i - K][j]
                  - psumB[i][j - K] + psumB[i - K][j - K];

            ans = min(ans, min(w, b));
        }
    }

    printf("%d\n", ans);
    return 0;
}