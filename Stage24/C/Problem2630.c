#include <stdio.h>

int N;
int paper[128][128];
int white = 0, blue = 0;

void check(int x, int y, int size) {
    int color = paper[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != color) {
                int half = size / 2;
                check(x, y, half);
                check(x, y + half, half);
                check(x + half, y, half);
                check(x + half, y + half, half);
                return;
            }
        }
    }

    if (color == 0) white++;
    else blue++;
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    check(0, 0, N);

    printf("%d\n%d\n", white, blue);
    return 0;
}