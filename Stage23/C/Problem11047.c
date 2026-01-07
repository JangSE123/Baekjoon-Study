#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int coin[N];
    int count = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &coin[i]);
    }

    for (int i = N - 1; i >= 0; i--) {
        if (K >= coin[i]) {
            count += K / coin[i];
            K %= coin[i];
        }
    }

    printf("%d", count);
    return 0;
}