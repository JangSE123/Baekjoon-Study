#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    char heard[N][21];
    char seen[M][21];
    char result[N < M ? N : M][21];
    int count = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", heard[i]);
    }

    qsort(heard, N, 21, cmp);

    for (int i = 0; i < M; i++) {
        scanf("%s", seen[i]);
        if (bsearch(seen[i], heard, N, 21, cmp)) {
            strcpy(result[count++], seen[i]);
        }
    }

    qsort(result, count, 21, cmp);

    printf("%d\n", count);
    
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}