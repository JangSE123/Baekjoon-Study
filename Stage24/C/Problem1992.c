#include <stdio.h>

int N;
int map[65][65];
char result[10000];
int idx = 0;

void quad(int x, int y, int size) {
    int first = map[x][y];
    int same = 1;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (map[i][j] != first) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }
    
    if(same) {
        result[idx++] = first + '0';
        return;
    }

    result[idx++] = '(';
    int half = size / 2;

    quad(x, y, half);
    quad(x, y + half, half);
    quad(x + half, y, half);
    quad(x + half, y + half, half);

    result[idx++] = ')';
}

int main(void) {
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    quad(0, 0, N);
    result[idx] = '\0';

    printf("%s\n", result);
    return 0;
}