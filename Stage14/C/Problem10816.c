#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y);
}

int lower_bound(int *arr, int n, int key) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int upper_bound(int *arr, int n, int key) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] <= key)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}


int main(void) {
    int N, M;
    scanf("%d", &N);

    int *cards = (int *)malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }

    qsort(cards, N, sizeof(int), cmp);

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        int lower = lower_bound(cards, N, target);
        int upper = upper_bound(cards, N, target);
        printf("%d", upper - lower);
        if (i < M - 1) printf(" ");
    }

    printf("\n");
    free(cards);
    return 0;
}