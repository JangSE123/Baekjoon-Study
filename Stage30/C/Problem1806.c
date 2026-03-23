#include <stdio.h>
#include <limits.h>

int main(void) {
    int N, S;
    scanf("%d %d", &N, &S);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int start = 0, end = 0;
    int sum = 0;
    int minLen = INT_MAX;

    while (1) {
        if (sum >= S) {
            if (minLen > end - start)
                minLen = end - start;
            sum -= arr[start++];
        } else {
            if (end == N) break;
            sum += arr[end++];
        }
    }

    if (minLen == INT_MAX)
        printf("0\n");
    else
        printf("%d\n", minLen);

    return 0;
}