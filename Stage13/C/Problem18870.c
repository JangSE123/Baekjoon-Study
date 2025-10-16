#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x > y) return 1;
    else if (x < y) return -1;
    else return 0;
}

int binary_search(int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void) {
    int N;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);
    int *sorted = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }

    qsort(sorted, N, sizeof(int), compare);

    int unique_count = 0;
    int *unique = (int *)malloc(sizeof(int) * N);
    unique[unique_count++] = sorted[0];
    for (int i = 1; i < N; i++) {
        if (sorted[i] != sorted[i - 1]) {
            unique[unique_count++] = sorted[i];
        }
    }

    for (int i = 0; i < N; i++) {
        int rank = binary_search(unique, unique_count, arr[i]);
        printf("%d ", rank);
    }
    printf("\n");
    
    free(arr);
    free(sorted);
    free(unique);
    return 0;
}