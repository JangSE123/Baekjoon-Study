#include <stdio.h>

int board[9][9];
int blanks[81][2];
int blank_count = 0;
int solved = 0;

void dfs(int idx) {
    if (idx == blank_count) {
        solved = 1;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }

        return;
    }

    int r = blanks[idx][0];
    int c = blanks[idx][1];

    for (int num = 1; num <= 9 && !solved; num++) {
        if (check(r, c, num)) {
            board[r][c] = num;
            dfs(idx + 1);
            board[r][c] = 0;
        }
    }
}

int check(int r, int c, int num) {
    for (int i = 0; i < 9; i++)
        if (board[r][i] == num || board[i][c] == num)
            return 0;

    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;
    for (int i = sr; i < sr + 3; i++)
        for (int j = sc; j < sc + 3; j++)
            if (board[i][j] == num)
                return 0;

    return 1;
}

int main(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0) {
                blanks[blank_count][0] = i;
                blanks[blank_count][1] = j;
                blank_count++;
            }
        }
    }

    dfs(0);
    return 0;
}