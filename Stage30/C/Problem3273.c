#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    qsort(arr, n, sizeof(int), compare);

    int start = 0;
    int end = n - 1;
    int count = 0;

    while (start < end) {
        int sum = arr[start] + arr[end];

        if (sum == x) {
            count++;
            start++;
            end--;
        } else if (sum < x) {
            start++;
        } else {
            end--;
        }
    }

    printf("%d\n", count);

    return 0;
}