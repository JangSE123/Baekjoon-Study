#include <stdio.h>

int main() {
    int N, M, i, j;
    scanf("%d %d", &N, &M);
    int arr[N];

    for (int x = 0; x < N; x++) {
        arr[x] = x + 1;
    }

    for (int x = 0; x < M; x++) {
        scanf("%d %d", &i, &j);
        int left = i - 1;
        int right = j - 1;

        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    for (int x = 0; x < N; x++) {
        printf("%d ", arr[x]);
    }

    return 0;
}