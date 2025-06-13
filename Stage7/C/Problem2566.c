#include <stdio.h>
#include <limits.h>

int main() {
    int matrix[9][9];
    int row = 0, col = 0, value = INT_MIN;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (matrix[i][j] > value) {
                value = matrix[i][j];
                row = i + 1;
                col = j + 1;
            }
        }
    }

    printf("%d\n%d %d", value, row, col);
    return 0;
}