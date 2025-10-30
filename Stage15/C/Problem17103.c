#include <stdio.h>
#include <stdbool.h>
#define MAX 1000000

int main(void) {
    bool isPrime[MAX + 1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int count = 0;

        if (isPrime[2] && isPrime[N - 2]) count++;

        for (int i = 3; i <= N / 2; i += 2) {
            if (isPrime[i] && isPrime[N - i]) count++;
        }

        printf("%d\n", count);
    }

    return 0;
}