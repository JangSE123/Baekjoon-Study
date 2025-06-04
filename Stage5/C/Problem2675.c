#include <stdio.h>
#include <string.h>

int main() {
    int T, R;
    scanf("%d", &T);
    char S[21];

    for (int i = 0; i < T; i++) {
        scanf("%d %s", &R, S);

        for (int j = 0; j < strlen(S); j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }

        printf("\n");
    }

    return 0;
}