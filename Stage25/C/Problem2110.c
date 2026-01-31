#include <stdio.h>
#include <stdlib.h>

static int N, C;
static int *house;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

static int canInstall(int dist) {
    int count = 1;
    int last = house[0];

    for (int i = 1; i < N; i++) {
        if (house[i] - last >= dist) {
            count++;
            last = house[i];
        }
    }
    return count >= C;
}

static int binarySearch() {
    int left = 1;
    int right = house[N - 1] - house[0];
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canInstall(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

int main(void) {
    scanf("%d %d", &N, &C);

    house = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &house[i]);
    }

    qsort(house, N, sizeof(int), compare);

    printf("%d\n", binarySearch());

    free(house);
    return 0;
}