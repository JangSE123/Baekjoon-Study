#include <stdio.h>
#include <string.h>

#define MAX 1001

char A[MAX], B[MAX];
int dp[MAX][MAX];

void lcs() {
    int n = strlen(A);
    int m = strlen(B);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) 
                            ? dp[i - 1][j] 
                            : dp[i][j - 1];
            }
        }
    }
}

void getLCS() {
    int i = strlen(A);
    int j = strlen(B);

    char result[MAX];
    int idx = 0;

    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            result[idx++] = A[i - 1];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    for (int k = idx - 1; k >= 0; k--) {
        printf("%c", result[k]);
    }
    printf("\n");
}

int main() {
    scanf("%s", A);
    scanf("%s", B);

    lcs();

    printf("%d\n", dp[strlen(A)][strlen(B)]);
    getLCS();

    return 0;
}