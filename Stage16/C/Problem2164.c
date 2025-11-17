#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int q[5000000];
    int front = 0;
    int rear = 0;

    for (int i = 1; i <= N; i++) {
        q[rear++] = i;
    }

    while (front + 1 < rear) {
        front++;
        q[rear++] = q[front++];
    }

    printf("%d\n", q[front]);
    return 0;
}