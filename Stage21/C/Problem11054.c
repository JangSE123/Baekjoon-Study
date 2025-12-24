#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int inc[N];
    for (int i = 0; i < N; i++) {
        inc[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    int dec[N];
    for (int i = N - 1; i >= 0; i--) {
        dec[i] = 1;
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[i]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, inc[i] + dec[i] - 1);
    }

    printf("%d", ans);
    return 0;
}