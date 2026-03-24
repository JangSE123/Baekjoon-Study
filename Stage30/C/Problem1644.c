#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int N;
    scanf("%d", &N);

    bool* isPrime = (bool*)malloc(sizeof(bool) * (N + 1));
    
    for (int i = 0; i <= N; i++) isPrime[i] = true;
    if (N >= 0) isPrime[0] = false;
    if (N >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int* primes = (int*)malloc(sizeof(int) * (N + 1));
    int size = 0;

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes[size++] = i;
        }
    }

    int left = 0, right = 0;
    int sum = 0;
    int count = 0;

    while (1) {
        if (sum >= N) {
            if (sum == N) count++;
            sum -= primes[left++];
        } else {
            if (right == size) break;
            sum += primes[right++];
        }
    }

    printf("%d\n", count);

    free(isPrime);
    free(primes);
    return 0;
}