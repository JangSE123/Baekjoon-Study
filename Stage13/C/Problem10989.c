#include <stdio.h>

int main(void) {

    int N;
    int count[10001] = {0};
    scanf("%d", &N);

    int num;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        count[num]++;
    }

    for (int i = 1; i <= 10000; i++) {
        while (count[i]-- > 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}