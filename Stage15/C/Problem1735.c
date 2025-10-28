#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(void) {
    int A, B, C, D;
    scanf("%d %d", &A, &B);
    scanf("%d %d", &C, &D);

    int numerator = A * D + B * C;
    int denominator = B * D;

    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    printf("%d %d\n", numerator, denominator);
    return 0;
}