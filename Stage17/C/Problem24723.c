#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int result = 1 << N;
    
    printf("%d", result);
    return 0;
}