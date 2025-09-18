#include <stdio.h>

int main(void) {

    int N;
    scanf("%d", &N);

    int side = (1 << N) + 1;
    int result = side * side;

    printf("%d", result);;
    return 0;
}