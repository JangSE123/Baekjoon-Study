#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *p1 = (int *)a;
    int *p2 = (int *)b;

    if (p1[0] == p2[0]) return p1[1] - p2[1];
    else return p1[0] - p2[0];
}

int main(void) {
    int N;
    scanf("%d", &N);
    int points[N][2];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    qsort(points, N, sizeof(points[0]), compare);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", points[i][0], points[i][1]);
    }

    return 0;
}