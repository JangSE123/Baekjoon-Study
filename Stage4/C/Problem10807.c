#include <stdio.h>

int main() {
    int N, v, count = 0;
    
    scanf("%d", &N);
    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &v);

    for (int i = 0; i < N; i++) {
        if (arr[i] == v) count++;
    }

    printf("%d\n", count);
    return 0;
}