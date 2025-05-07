#include <stdio.h>

int main() {
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);
    
    if (A > 0 && A < 10 && B > 0 && B < 10) {
        printf("%d\n", A + B);
    } else {
        printf("값이 0보다 크고 10보다 작아야 합니다.");
    }

    return 0;
}