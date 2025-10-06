#include <stdio.h>

int main(void) {

    int N;
    scanf("%d", &N);
    int result = -1;

    for (int i = N / 5; i >= 0; i--) {
        int remain = N - (i * 5);

        if (remain % 3 == 0) {
            result = i + (remain / 3);
            break;
        }
    }

    printf("%d", result);
    return 0;
}