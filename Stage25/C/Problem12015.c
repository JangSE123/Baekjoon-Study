#include <stdio.h>

int lower_bound(int arr[], int size, int target) {
    int left = 0, right = size;

    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main(void) {
    int N;
    scanf("%d", &N);

    int lis[N];
    int size = 0;

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        int idx = lower_bound(lis, size, x);
        lis[idx] = x;

        if (idx == size)
            size++;
    }

    printf("%d\n", size);
    return 0;
}