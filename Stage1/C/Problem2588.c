#include <stdio.h>

int main() {
    int num1, num2, num3, num4, num5, num6;
    scanf("%d %d", &num1, &num2);

    num3 = num1 * (num2 % 10);
    num4 = num1 * ((num2 % 100) / 10);
    num5 = num1 * (num2 / 100);

    num6 = num3 + (num4 * 10) + (num5 * 100);

    printf("%d\n", num3);
    printf("%d\n", num4);
    printf("%d\n", num5);
    printf("%d\n", num6);

    return 0;
}