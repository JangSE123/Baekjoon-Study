#include <stdio.h>

int main() {
    int defaultPieces[6] = {1, 1, 2, 2, 2, 8};
    int piece;

    for (int i = 0; i < 6; i++) {
        scanf("%d", &piece);
        printf("%d ", defaultPieces[i] - piece);
    }

    return 0;
}