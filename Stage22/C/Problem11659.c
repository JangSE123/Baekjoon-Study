#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int prefix[N + 1];
    prefix[0] = 0;
    
    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);
        prefix[i] = prefix[i - 1] + num;
    }

    while (M--) {
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%d\n", prefix[j] - prefix[i - 1]);
    }
    
    return 0;
}