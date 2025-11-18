#include <stdio.h>

#define MAX 1000

typedef struct {
    int num;
    int val;
} Balloon;

int main() {
    int N;
    scanf("%d", &N);

    Balloon balloons[MAX];
    for (int i = 0; i < N; i++) {
        balloons[i].num = i + 1;
        scanf("%d", &balloons[i].val);
    }

    int idx = 0;
    int count = N;

    while (count--) {
        printf("%d ", balloons[idx].num);

        int move = balloons[idx].val;

        for (int i = idx; i < N - 1; i++)
            balloons[i] = balloons[i + 1];

        N--;

        if (N == 0) break;

        if (move > 0) {
            idx = (idx + move - 1) % N;
        } else {
            idx = (idx + move) % N;
            if (idx < 0) idx += N;
        }
    }

    return 0;
}