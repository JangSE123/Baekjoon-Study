#include <stdio.h>

void hanoi(int n, int start, int mid, int end) {
    if (n == 1) {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n - 1, start, end, mid);
    printf("%d %d\n", start, end);
    hanoi(n - 1, mid, start, end);
}

int main(void) {
    int N;
    scanf("%d", &N);

    printf("%d\n", (1 << N) - 1);

    hanoi(N, 1, 2, 3);

    return 0;
}