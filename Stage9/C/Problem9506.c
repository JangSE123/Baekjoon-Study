#include <stdio.h>

int main(void) {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == -1) break;

        int sum = 0;
        int divisors[1000];
        int count = 0;

        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                divisors[count++] = i;
                sum += i;
            }
        }
        
        if (sum == n) {
            printf("%d = ", n);
            for (int i = 0; i < count; i++) {
                if (i > 0) printf(" + ");
                printf("%d", divisors[i]);
            }
            printf("\n");
        } else {
            printf("%d is NOT perfect.\n", n);
        }
    }

    return 0;
}