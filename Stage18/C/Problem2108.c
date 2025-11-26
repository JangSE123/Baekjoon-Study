#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int N;
    scanf("%d", &N);

    int arr[500000];
    int freq[8001] = {0};
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        freq[arr[i] + 4000]++;
    }

    int avg = (int) round((double) sum / N);

    qsort(arr, N, sizeof(int), compare);
    int mid = arr[N / 2];

    int maxFreq = 0;
    for (int i = 0; i < 8001; i++) {
        if (freq[i] > maxFreq) maxFreq = freq[i];
    }

    int mode;
    int count = 0;
    for (int i = 0; i < 8001; i++) {
        if (freq[i] == maxFreq) {
            mode = i - 4000;
            count++;
            if (count == 2) break;
        }
    }

    int range = arr[N - 1] - arr[0];

    printf("%d\n%d\n%d\n%d\n", avg, mid, mode, range);

    return 0;
}