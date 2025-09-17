#include <stdio.h>

int main(void) {

    int T, C;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &C);

        int quarters = C / 25;
        C %= 25;

        int dimes = C / 10;
        C %= 10;

        int nickels = C / 5;
        C %= 5;

        int pennies = C;

        printf("%d %d %d %d\n", quarters, dimes, nickels, pennies);
    }

    return 0;
}