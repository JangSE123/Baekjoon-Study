#include <stdio.h>

int main() {
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    int W = (A + B) % C;
    int X = ((A % C) + (B % C)) % C;
    int Y = (A * B) % C;
    int Z = ((A % C) * (B % C)) % C;

    printf("%d\n", W);
    printf("%d\n", X);
    printf("%d\n", Y);
    printf("%d\n", Z);

    return 0;
}