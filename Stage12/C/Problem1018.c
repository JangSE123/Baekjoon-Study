#include <stdio.h>
#include <string.h>

char board[51][51];

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int answer = 64;
    for (int x = 0; x <= N - 8; x++) {
        for (int y = 0; y <= M - 8; y++) {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    char current = board[x + i][y + j];
                    char expected1 = ((i + j) % 2 == 0) ? 'W' : 'B';
                    char expected2 = ((i + j) % 2 == 0) ? 'B' : 'W';
                    if (current != expected1) cnt1++;
                    if (current != expected2) cnt2++;
                }
            }
            int min = (cnt1 < cnt2) ? cnt1 : cnt2;
            if (min < answer) answer = min;
        }
    }

    printf("%d\n", answer);
    return 0;
}