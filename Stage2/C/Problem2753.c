#include <stdio.h>
#include <stdbool.h>

int main() {
    int year;
    scanf("%d", &year);
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    printf("%d\n", leapYear ? 1 : 0);

    return 0;
}