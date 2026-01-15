#include <stdio.h>

#define MAX 2200

int N;
int paper[MAX][MAX];
int minus = 0, zero = 0, plus = 0;

void countPaper(int x, int y, int size) {
    int first = paper[x][y];
    int same = 1;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (first == -1) minus++;
        else if (first == 0) zero++;
        else plus++;
        return;
    }

    int newSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            countPaper(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    countPaper(0, 0, N);

    printf("%d\n%d\n%d\n", minus, zero, plus);
    return 0;
}