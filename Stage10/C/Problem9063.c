#include <stdio.h>
#include <limits.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;

    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    int width = maxX - minX;
    int height = maxY - minY;

    printf("%d\n", width * height);
    return 0;
}