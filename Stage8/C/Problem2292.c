#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    if (N == 1) {
        printf("1");
        return 0;
    }

    int layer = 1;
    int maxNum = 1;

    while (maxNum < N) {
        maxNum += 6 * layer;
        layer++;
    }

    printf("%d" ,layer);
    return 0;
}