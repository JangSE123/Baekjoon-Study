#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int q[5000];
    int front = 0, rear = N;

    for (int i = 0; i < N; i++) {
        q[i] = i + 1;
    }

    printf("<");

    int count = N;
    int index = 0;

    while (count > 0) {
        index = (index + K - 1) % count;

        printf("%d", q[index]);

        for (int i = index; i < count - 1; i++) {
            q[i] = q[i + 1];
        }

        count--;

        if (count > 0) printf(", ");
        else printf(">");
    }

    return 0;
}