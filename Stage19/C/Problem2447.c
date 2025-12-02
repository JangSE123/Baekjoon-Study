#include <stdio.h>

char board[2200][2200];

void draw(int x, int y, int size) {
    if (size == 1) return;

    int newSize = size / 3;

    for (int i = x + newSize; i < x + 2 * newSize; i++) {
        for (int j = y + newSize; j < y + 2 * newSize; j++) {
            board[i][j] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            draw(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '*';
        }
    }

    draw(0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }

    return 0;
}