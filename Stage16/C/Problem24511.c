#include <stdio.h>

#define MAX 400000

int dq[MAX];
int front = 0; back = 0;

int main(void) {
    int N;
    scanf("%d", &N);

    int A[N], B[N];

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);

    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == 0) {
            dq[back++] = B[i];
        }
    }

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);

        dq[back++] = x;
        printf("%d ", dq[front++]);
    }

    return 0;
}