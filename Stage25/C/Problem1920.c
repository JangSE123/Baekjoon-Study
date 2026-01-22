#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int binarySearch(int *arr, int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) return 1;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main(void) {
    int N;
    scanf("%d", &N);

    int arr[100000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), cmp);

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        printf("%d\n", binarySearch(arr, N, target));
    }
    
    return 0;
}