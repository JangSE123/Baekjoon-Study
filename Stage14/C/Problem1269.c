#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int *A = malloc(sizeof(int) * N);
    int *B = malloc(sizeof(int) * M);

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < M; i++) scanf("%d", &B[i]);

    qsort(A, N, sizeof(int), cmp);
    qsort(B, M, sizeof(int), cmp);

    int i = 0, j = 0;
    int common = 0;

    while (i < N && j < M) {
        if (A[i] == B[j]) {
            common++;
            i++; j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }

    int result = (N + M) - 2 * common;
    printf("%d\n", result);

    free(A);
    free(B);
    return 0;
}