#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    long long left = 1;
    long long right = (long long)N * N;
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 1; i <= N; i++) {
            long long tmp = mid / i;
            if (tmp > N) tmp = N;
            count += tmp;
        }

        if (count >= K) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}