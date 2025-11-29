#include <stdio.h>
#include <stdlib.h>

int A[500000], tmp[500000];
int K, count = 0, result = -1;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int t = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
        count++;
        if (count == K) result = tmp[t - 1];
    }

    while (i <= mid) {
        tmp[t++] = A[i++];
        count++;
        if (count == K) result = tmp[t - 1];
    }

    while (j <= right) {
        tmp[t++] = A[j++];
        count++;
        if (count == K) result = tmp[t - 1];
    }

    for (int x = left; x <= right; x++)
        A[x] = tmp[x];
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main(void) {
    int N;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    mergeSort(0, N - 1);
    printf("%d\n", result);

    return 0;
}