#include <stdio.h>

int main() {
    int T, A, B;
    scanf("%d", &T);
    int results[T];

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);
        results[i] = A + B;
    }

    for (int i = 0; i < T; i++) {
        printf("%d\n", results[i]);
    }
    
    return 0;
}