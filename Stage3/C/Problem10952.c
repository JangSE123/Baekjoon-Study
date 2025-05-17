#include <stdio.h>

int main() {
    int A, B;
    int results[1000];
    int index = 0;

    while (1) {
        scanf("%d %d", &A, &B);

        if (A == 0 && B == 0) {
            break;
        }

        results[index++] = A + B;    
    }

    for (int i = 0; i < index; i++) {
        printf("%d\n", results[i]);
    }
}