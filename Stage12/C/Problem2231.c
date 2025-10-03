#include <stdio.h>
#include <math.h>

int main(void) {

    int N;
    scanf("%d", &N);
    int result = 0;
    int start = N - 9 * ((int)log10(N) + 1);
    if (start < 1) start = 1;

    for (int i = start; i < N; i++) {
        int sum = i;
        int temp = i;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) {
            result = i;
            break;
        }
    }

    printf("%d\n", result);
    return 0;
}