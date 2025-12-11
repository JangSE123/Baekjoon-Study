#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N;
int S[21][21];
int visited[21];
int answer = INT_MAX;

int abs(int x) { return x < 0 ? -x : x; }

int calcDiff() {
    int start = 0, link = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (visited[i] && visited[j]) {
                start += S[i][j] + S[j][i];
            }
            else if (!visited[i] && !visited[j]) {
                link += S[i][j] + S[j][i];
            }
        }
    }
    return abs(start - link);
}

void dfs(int idx, int count) {
    if (count == N / 2) {
        int diff = calcDiff();
        if (diff < answer) answer = diff;
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i + 1, count + 1);
            visited[i] = 0;
        }
    }
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    dfs(0, 0);

    printf("%d\n", answer);

    return 0;
}