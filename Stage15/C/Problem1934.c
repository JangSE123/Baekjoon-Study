#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(void) {
    int T, A, B;
    scanf("%d", &T);

    int result = 0;

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", lcm(A, B));
    }

    return 0;
}