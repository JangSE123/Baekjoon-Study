#include <stdio.h>

int main(void) {
    int K, N;
    scanf("%d %d", &K, &N);

    long long arr[K];
    long long max = 0;

    for (int i = 0; i < K; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    long long left = 1;
    long long right = max;
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long count = 0;
        for (int i = 0; i < K; i++) {
            count += arr[i] / mid;
        }

        if (count >= N) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld", answer);
    return 0;
}