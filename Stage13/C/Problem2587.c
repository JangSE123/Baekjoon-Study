#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {

    int arr[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, 5, sizeof(int), compare);

    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    int avg = sum / 5;
    int median = arr[2];

    printf("%d\n%d\n", avg, median);
    return 0;
}