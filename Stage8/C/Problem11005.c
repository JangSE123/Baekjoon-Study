#include <stdio.h>

int main(void) {

    long long N;
    int B;
    char result[100];
    int idx = 0;

    scanf("%lld %d", &N, &B);

    while (N > 0) {
        int remainder = N % B;
        if (remainder < 10) {
            result[idx++] = remainder + '0';
        } else {
            result[idx++] = remainder - 10 + 'A';
        }
        N /= B;
    }

    for (int i = idx - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");

    return 0;
}