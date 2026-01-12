#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long dist[n - 1];
    long long price[n];

    for (int i = 0; i < n - 1; i++)
        scanf("%lld", &dist[i]);

    for (int i = 0; i < n; i++)
        scanf("%lld", &price[i]);

    long long minPrice = price[0];
    long long cost = 0;

    for (int i = 0; i < n - 1; i++) {
        if (price[i] < minPrice)
            minPrice = price[i];
        cost += minPrice * dist[i];
    }

    printf("%lld\n", cost);
    return 0;
}