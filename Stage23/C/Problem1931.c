#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    if (m1 -> end == m2 -> end)
        return m1 -> start - m2 -> start;
    return m1 -> end - m2 -> end;
}

int main(void) {
    int N;
    scanf("%d", &N);

    Meeting arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, N, sizeof(Meeting), compare);

    int count = 0;
    int endTime = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i].start >= endTime) {
            count++;
            endTime = arr[i].end;
        }
    }

    printf("%d\n", count);
    return 0;
}
