#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LEN 11

typedef struct {
    char word[MAX_LEN];
    int freq;
} Word;

int compare(const void *a, const void *b) {
    Word *x = (Word *)a;
    Word *y = (Word *)b;

    if (x->freq != y->freq)
        return y->freq - x->freq;

    int lenX = strlen(x->word);
    int lenY = strlen(y->word);
    if (lenX != lenY)
        return lenY - lenX;

    return strcmp(x->word, y->word);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Word arr[MAX_N];
    int size = 0;

    char temp[MAX_LEN];
    for (int i = 0; i < N; i++) {
        scanf("%s", temp);

        if (strlen(temp) < M) continue;

        int found = -1;
        for (int j = 0; j < size; j++) {
            if (strcmp(arr[j].word, temp) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(arr[size].word, temp);
            arr[size].freq = 1;
            size++;
        }
        else {
            arr[found].freq++;
        }
    }

    qsort(arr, size, sizeof(Word), compare);

    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i].word);
    }

    return 0;
}