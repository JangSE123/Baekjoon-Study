#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(void) {
    int N;
    scanf("%d", &N);

    int arr[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    int sum = 0, prefix = 0;
    for (int i = 0; i < N; i++) {
        prefix += arr[i];
        sum += prefix;
    }

    printf("%d\n", sum);
    return 0;
}