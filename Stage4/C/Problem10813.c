#include <stdio.h>

int main() {
    int N, M, i, j, temp;
    scanf("%d %d", &N, &M);
    int arr[N];

    for (int x = 0; x < N; x++) {
        arr[x] = x + 1;
    }

    for (int x = 0; x < M; x++) {
        scanf("%d %d", &i, &j);
        temp = arr[i - 1];
        arr[i - 1] = arr[j - 1];
        arr[j - 1] = temp;
    }

    for (int x = 0; x < N; x++) {
        printf("%d ", arr[x]);
    }

    return 0;
}