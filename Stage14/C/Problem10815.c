#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}

int main(void) {
    int N, M;
    scanf("%d", &N);

    int *cards = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }

    qsort(cards, N, sizeof(int), compare);

    scanf("%d", &M);
    int num;

    for (int i = 0; i < M; i++) {
        scanf("%d", &num);

        if (bsearch(&num, cards, N, sizeof(int), compare) != NULL)
            printf("1 ");
        else
            printf("0 ");
    }

    free(cards);
    return 0;
}