#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    B += C;

    if (B >= 60) {
        A += B / 60;
        B %= 60;
    }
    
    if (A >= 24) {
        A -= 24;
    }

    printf("%d %d\n", A, B);

    return 0;
}