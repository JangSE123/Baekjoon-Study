#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int result = N * (N - 1);
    
    printf("%d", result);
    return 0;
}