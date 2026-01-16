#include <stdio.h>

int main(void) {
    int N, M, K;
    int A[100][100], B[100][100];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    scanf("%d %d", &M, &K);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int sum = 0;
            for (int t = 0; t < M; t++) {
                sum += A[i][t] * B[t][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}