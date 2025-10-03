#include <stdio.h>

int main(void) {

    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    int denominator = a * e - b * d;
    int x = (c * e - b * f) / denominator;
    int y = (a * f - c * d) / denominator;

    printf("%d %d", x, y);
    return 0;
}