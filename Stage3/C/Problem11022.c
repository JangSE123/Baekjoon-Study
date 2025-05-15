#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int A[T], B[T], C[T];

    for (int x = 0; x < T; x++) {
        scanf("%d %d", &A[x], &B[x]);
        C[x] = A[x] + B[x];
    }

    for (int x = 0; x < T; x++) {
        printf("Case #%d: %d + %d = %d\n", x + 1, A[x], B[x], C[x]);
    }

    return 0;
}