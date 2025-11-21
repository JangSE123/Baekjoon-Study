#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int N, M;
        scanf("%d %d", &N, &M);

        long res = 1;
        for (int i = 1; i <= N; i++) {
            res = res * (M - i + 1) / i;
        }

        printf("%ld\n", res);
    }

    return 0;
}