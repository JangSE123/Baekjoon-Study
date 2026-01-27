#include <stdio.h>

int main(void) {
    int N;
    long long M;
    scanf("%d %lld", &N, &M);

    long long tree[N];
    long long max = 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld", &tree[i]);
        if (tree[i] > max) max = tree[i];
    }

    long long left = 0;
    long long right = max;
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long total = 0;
        for (int i = 0; i < N; i++) {
            if (tree[i] > mid) total += tree[i] - mid;
        }

        if (total >= M) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}