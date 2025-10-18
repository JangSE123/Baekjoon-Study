#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 501

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    char **S = malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++) {
        S[i] = malloc(sizeof(char) * MAX_LEN);
        scanf("%s", S[i]);
    }

    qsort(S, N, sizeof(char *), compare);

    int count = 0;
    char word[MAX_LEN];

    for (int i = 0; i < M; i++) {
        scanf("%s", word);
        char *key = word;
        if (bsearch(&key, S, N, sizeof(char *), compare) != NULL) {
            count++;
        }
    }

    printf("%d\n", count);

    for (int i = 0; i < N; i++) free(S[i]);
    free(S);

    return 0;
}