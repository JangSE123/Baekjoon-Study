#include <stdio.h>

int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int main(void) {
    int N;
    scanf("%d", &N);

    int trees[100000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &trees[i]);
    }

    int distances[100000];
    for (int i = 0; i < N - 1; i++) {
        distances[i] = trees[i + 1] - trees[i];
    }

    int gcd = distances[0];
    for (int i = 1; i < N - 1; i++) {
        gcd = getGCD(gcd, distances[i]);
    }

    int total = (trees[N - 1] - trees[0]) / gcd + 1;
    printf("%d\n", total - N);

    return 0;
}