#include <stdio.h>
#include <math.h>

int N;
int col[15];
int count = 0;

void dfs(int row) {
    if (row == N) {
        count++;
        return;
    }

    for (int i = 0; i < N; i++) {
        col[row] = i;
        if (isPossible(row)) {
            dfs(row + 1);
        }
    }
}

int isPossible(int row) {
    for (int i = 0; i < row; i++) {
        if (col[i] == col[row] || abs(col[i] - col[row]) == row - i) {
                return 0;
        }
    }
    return 1;
}

int main(void) {
    scanf("%d", &N);
    dfs(0);

    printf("%d\n", count);
    return 0;
}