#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

typedef struct {
    char name[21];
    int num;
} Poke;

Poke pokes[MAX];
char numToName[MAX][21];

int cmp(const void *a, const void *b) {
    return strcmp(((Poke*)a)->name, ((Poke*)b)->name);
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", pokes[i].name);
        strcpy(numToName[i], pokes[i].name);
        pokes[i].num = i;
    }

    qsort(pokes + 1, n, sizeof(Poke), cmp);

    char query[21];
    for (int i = 0; i < m; i++) {
        scanf("%s", query);
        if (query[0] >= '0' && query[0] <= '9') {
            int num = atoi(query);
            printf("%s\n", numToName[num]);
        } else {
            Poke key = {.name = ""};
            strcpy(key.name, query);
            Poke *res = bsearch(&key, pokes + 1, n, sizeof(Poke), cmp);
            printf("%d\n", res->num);
        }
    }
    return 0;
}