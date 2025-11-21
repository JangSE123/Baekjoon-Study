#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int result = 1;
    
    for (int i = 1; i <= K; i++) {
        result = result * (N - i + 1) / i;
    }

    printf("%d\n", result);

    return 0;
}