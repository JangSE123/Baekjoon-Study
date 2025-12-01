#include <stdio.h>

char arr[600000];

void cantor(int start, int size) {
    if (size == 1) return;

    int len = size / 3;

    for (int i = start + len; i < start + len * 2; i++) {
        arr[i] = ' ';
    }

    cantor(start, len);
    cantor(start + len * 2, len);
}

int main(void) {
    int N;

    while (scanf("%d", &N) != EOF) {
        int size = 1;
        for (int i = 0; i < N; i++)
            size *= 3;

        for (int i = 0; i < size; i++)
            arr[i] = '-';

        cantor(0, size);

        for (int i = 0; i < size; i++)
            putchar(arr[i]);
        putchar('\n');
    }

    return 0;
}