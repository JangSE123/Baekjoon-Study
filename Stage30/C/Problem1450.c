#include <stdio.h>
#include <stdlib.h>

int N, C;
int arr[30];

int left[1 << 15];
int right[1 << 15];
int l_size = 0, r_size = 0;

void dfs(int start, int end, int sum, int* list, int* size) {
    if (sum > C) return;

    if (start == end) {
        list[(*size)++] = sum;
        return;
    }

    dfs(start + 1, end, sum, list, size);

    dfs(start + 1, end, sum + arr[start], list, size);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int upper_bound(int* arr, int size, int target) {
    int left = 0, right = size;

    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) left = mid + 1;
        else right = mid;
    }

    return left;
}

int main(void) {
    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    dfs(0, N / 2, 0, left, &l_size);
    dfs(N / 2, N, 0, right, &r_size);

    qsort(right, r_size, sizeof(int), compare);

    long long count = 0;

    for (int i = 0; i < l_size; i++) {
        if (left[i] > C) continue;

        int remain = C - left[i];

        int idx = upper_bound(right, r_size, remain);
        count += idx;
    }

    printf("%lld\n", count);

    return 0;
}