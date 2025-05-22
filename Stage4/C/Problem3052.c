#include <stdio.h>

int main() {
    int A, B = 42;
    int check[42] = {0};
    int count = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &A);
        int mod = A % B; 

        if (check[mod] == 0) {
            check[mod] = 1;
            count++;
        }
    }

    printf("%d", count);

    return 0;
}