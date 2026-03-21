#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    int left = 0;
    int right = N - 1;

    int ansL = arr[left];
    int ansR = arr[right];
    long long min = 2000000000LL;

    while (left < right) {
        long long sum = (long long)arr[left] + arr[right];

        if (llabs(sum) < min) {
            min = llabs(sum);
            ansL = arr[left];
            ansR = arr[right];
        }

        if (sum < 0) left++;
        else right--;
    }

    printf("%d %d\n", ansL, ansR);

    free(arr);
    return 0;
}