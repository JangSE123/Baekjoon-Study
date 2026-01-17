#include <stdio.h>

#define MOD 1000
int N;
long long B;

void multiply(int a[5][5], int b[5][5], int result[5][5]) {
    int temp[5][5] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= MOD;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] = temp[i][j];
}

void power(int matrix[5][5], long long exp, int result[5][5]) {
    if (exp == 1) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result[i][j] = matrix[i][j];
        return;
    }

    int half[5][5];
    power(matrix, exp / 2, half);

    int temp[5][5];
    multiply(half, half, temp);

    if (exp % 2 == 1) {
        multiply(temp, matrix, result);
    } else {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result[i][j] = temp[i][j];
    }
}

int main(void) {
    int A[5][5];
    int result[5][5];

    scanf("%d %lld", &N, &B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            A[i][j] %= MOD;
        }
    }

    power(A, B, result);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}