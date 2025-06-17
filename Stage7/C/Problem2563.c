#include <stdio.h>

int main(void) {
    int N, x, y, count = 0;
    int arr[100][100] ={0,};
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);

        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                arr[j][k] = 1;
            }
        }

    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] == 1) {
                count++;
            }
        }
    }

    printf("%d", count);
    return 0;
}