#include <stdio.h>

int main() {
    int X, N, a, b;
    int totalPrice = 0;
    scanf("%d %d", &X, &N);

    for (int i =0; i < N; i++) {
        scanf("%d %d", &a, &b);
        totalPrice += a * b;
    }

    printf("%s\n", X == totalPrice ? "Yes" : "No");

    return 0;
}