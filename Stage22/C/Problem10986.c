#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    long long count[1000] = {0};
    long long sum = 0;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        scanf("%lld", &x);

        sum += x;
        int mod = sum % M;

        if (mod == 0)
            answer++;

        count[mod]++;
    }

    for (int i = 0; i < M; i++) {
        if (count[i] >= 2) answer += count[i] * (count[i] - 1) / 2;
    }

    printf("%lld\n", answer);
    return 0;
}