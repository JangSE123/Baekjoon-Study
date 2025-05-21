#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int arr [N];
    int i, j, k;

    for (int x = 0; x < N; x++) {
        arr[x] = 0;
    }

    for (int x = 0; x < M; x++) {
        scanf("%d %d %d", &i, &j, &k);

        for (int index = i - 1; index <= j - 1; index++) {
            arr[index] = k;
        }
    }

    for (int x = 0; x < N; x++) {
        printf("%d ", arr[x]);
    }

    return 0;
}