#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20000
#define LEN 51

int compare(const void *a, const void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) return len1 - len2;
    return strcmp(s1, s2);
}

int main(void) {
    int N;
    scanf("%d", &N);

    char *words[MAX];
    for (int i = 0; i < N; i++) {
        words[i] = malloc(LEN);
        scanf("%s", words[i]);
    }

    qsort(words, N, sizeof(char *), compare);

    printf("%s\n", words[0]);

    for (int i = 1; i < N; i++) {
        if (strcmp(words[i], words[i - 1]) != 0) {
            printf("%s\n", words[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        free(words[i]);
    }

    return 0;
}