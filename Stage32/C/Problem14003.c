#include <stdio.h>
#include <stdlib.h>

int *arr, *lis, *prev, *lastIdx;
int N;

int lower_bound(int *a, int len, int target) {
    int left = 0, right = len;
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}

int lisProcess() {
    int len = 0;

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(lis, len, arr[i]);

        lis[pos] = arr[i];
        lastIdx[pos] = i;

        prev[i] = (pos > 0) ? lastIdx[pos - 1] : -1;

        if (pos == len) len++;
    }

    return len;
}

int getLastIndex(int len) {
    return lastIdx[len - 1];
}

void trace(int start, int len) {
    int *stack = (int*)malloc(sizeof(int) * len);
    int top = 0;

    while (start != -1) {
        stack[top++] = arr[start];
        start = prev[start];
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    free(stack);
}

int main() {
    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int) * N);
    lis = (int*)malloc(sizeof(int) * N);
    prev = (int*)malloc(sizeof(int) * N);
    lastIdx = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int len = lisProcess();
    int last = getLastIndex(len);

    printf("%d\n", len);
    trace(last, len);

    free(arr);
    free(lis);
    free(prev);
    free(lastIdx);

    return 0;
}