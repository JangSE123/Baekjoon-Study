#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    double result = (double) A / B;

    printf("%.15g\n", result);
    return 0;
}